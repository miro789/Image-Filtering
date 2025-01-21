#include "helpers.h"
#include <math.h>
#define NUM_COLOR 3
#define min(a, b) ((a) < (b) ? (a) : (b)) // check min inside sepia

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop to each 2D matrix image [][]
    // calculate average of 3 color and updated new value
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            int avg =
                round((float) (pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue) / NUM_COLOR);

            // RGBTRIPLE pixel = image[i][j];
            // int avg = round((float) (pixel.rgbRed + pixel.rgbGreen + pixel.rgbBlue) / NUM_COLOR);
            // image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
            pixel->rgbtRed = pixel->rgbtGreen = pixel->rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // follow the calculate
    // be sure not exceed the max value 255
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            image[i][j].rgbtRed = min(255, sepiaRed);
            image[i][j].rgbtGreen = min(255, sepiaGreen);
            image[i][j].rgbtBlue = min(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // swap the RGBTRIPLE pixel each row
    for (int i = 0; i < height; i++) // columns
    {
        // for (int j = 0; j < width / 2; j++) // rows
        // {
        //     RGBTRIPLE temp = image[i][j];
        //     image[i][j] = image[i][width - 1 - j];
        //     image[i][width - 1 - j] = temp;
        // }

        int left = 0;
        int right = width - 1;
        while (left <= right)
        {
            RGBTRIPLE temp = image[i][left];
            image[i][left] = image[i][right];
            image[i][right] = temp;
            left++;
            right--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // // Create a copy of image
    // RGBTRIPLE copy[height][width];
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         copy[i][j] = image[i][j];
    //     }
    // }

    // copy the original pixel values before calculate the averages
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            // Calculate the pixeds around (3x3)
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 &&
                        l < width) // exclude the values pixel are outside of the image
                    {
                        sumRed += image[k][l].rgbtRed;
                        sumGreen += image[k][l].rgbtGreen;
                        sumBlue += image[k][l].rgbtBlue;
                        count++;
                    }
                }
            }
            // Calculate the average of pixels around
            temp[i][j].rgbtRed = round((float) sumRed / count);
            temp[i][j].rgbtGreen = round((float) sumGreen / count);
            temp[i][j].rgbtBlue = round((float) sumBlue / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the original image to ensure updates to the original image do not affect the
    // computation of neighboring pixels.
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop through each pixel in the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            // Sum the values of the neighboring pixels
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check bounds to ensure valid neighbors
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumRed += copy[ni][nj].rgbtRed;
                        sumGreen += copy[ni][nj].rgbtGreen;
                        sumBlue += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Update the pixel values in the original image
            image[i][j].rgbtRed = round(sumRed / (float) count);
            image[i][j].rgbtGreen = round(sumGreen / (float) count);
            image[i][j].rgbtBlue = round(sumBlue / (float) count);
        }
    }
}
