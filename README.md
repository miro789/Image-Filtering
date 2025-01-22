# Image-Filtering
What does it even mean to filter an image? We can think of filtering an image as taking the pixels of some original image, and modifying each pixel in such a way that a particular effect is apparent in the resulting image.

## Table of Contents

- [Overview](#overview)
- [Key Points](#key-points)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)

## Overview
This problem set is part of CS50's Introduction to Computer Science course [CS50 Filter Project](https://cs50.harvard.edu/x/2025/psets/4/filter/less/). In this project, I used C to implement a program that applies filters to images, similar to those found in popular photo editing applications. I writed functions to convert images to grayscale, reflect images horizontally, apply a blur effect, and detect edges using the Sobel operator.



## Key Points
- **Graysacle**: Convert color images to black and white by averaging the red, green, and blue values of each pixel.

<div style="display: flex; justify-content: space-around; align-items: center;">
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/images/yard.bmp" alt="Origin Image" width="45%"/>
        <br />
        <span>Original Image</span>
    </div>
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/outputs/grey.png" alt="Grey Image" width="45%"/>
        <br />
        <span>Grey Mode</span>
    </div>
</div>

- **Sepia**: Convert images to a reddish-brown tone by recalculating each pixel's colors using weighted formulas for red, green, and blue. Cap values at 255 and round to the nearest integer..

<div style="display: flex; justify-content: space-around; align-items: center;">
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/images/yard.bmp" alt="Origin Image" width="25%"/>
        <br />
        <span>Original Image</span>
    </div>
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/outputs/sepia.png" alt="Sepia Image" width="25%"/>
        <br />
        <span>Sepia Mode</span>
    </div>
</div>

<table>
  <tr>
    <td align="center">
      <img src="https://github.com/miro789/Image-Filtering/blob/main/images/yard.bmp" alt="Original Image" width="45%"/>
      <br/>
      <span>Original Image</span>
    </td>
    <td align="center">
      <img src="https://github.com/miro789/Image-Filtering/blob/main/outputs/sepia.png" alt="Sepia Image" width="45%"/>
      <br/>
      <span>Sepia Mode</span>
    </td>
  </tr>
</table>


- **Reflect**: Reflect images horizontally, creating a mirror image effect by swapping pixels from left to right.

<div style="display: flex; justify-content: space-around; align-items: center;">
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/images/yard.bmp" alt="Origin Image" width="30%"/>
        <br />
        <span>Original Image</span>
    </div>
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/outputs/reflect.png" alt="Reflect Image" width="30%"/>
        <br />
        <span>Reflect Mode</span>
    </div>
</div>


- **Blur**: Apply a box blur to soften the image by averaging the colors of neighboring pixels.

<div style="display: flex; justify-content: space-around; align-items: center;">
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/images/yard.bmp" alt="Origin Image" width="35%"/>
        <br />
        <span>Original Image</span>
    </div>
    <div style="text-align: center; margin: 10px;">
        <img src="https://github.com/miro789/Image-Filtering/blob/main/outputs/blur.png" alt="Blur Image" width="35%"/>
        <br />
        <span>Blur Mode</span>
    </div>
</div>


## Data Structures

- **Pixels**: Each pixel in an image is represented as a structure (RGBTRIPLE) that contains three fields for the red, green, and blue values.

```C
    typedef struct
    {
        BYTE rgbtBlue;
        BYTE rgbtGreen;
        BYTE rgbtRed;
    }
RGBTRIPLE;
```

- **Image**: The image itself is represented as a 2D array of RGBTRIPLE structures, where each element corresponds to a pixel.
```C
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Do somethings
        }
    }
```

## Algorithms

- **Two-pointer Technique:**: Used in horizontal reflection to swap pixels from left to right.

- **Nested Loops**: Employed to iterate over each pixel in the image for applying transformations.

- **Color Conversion Formulas**: Used in the sepia filter to recalculate each pixel's red, green, and blue values using weighted 
formulas.

- **Box Blur**: Box Blur: Applies a blur effect by averaging the colors of each pixel's neighboring pixels.
