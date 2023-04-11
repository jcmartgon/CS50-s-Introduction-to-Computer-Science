// Author: Jesus Carlos Martinez Gonzalez
// Date: 08/04/2023
// Filter-more

#include "helpers.h"
#include <math.h> // math(), sqrt(), pow()

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Pixel and its RGB elements
            RGBTRIPLE pixel = image[i][j];
            float red = pixel.rgbtRed;
            float green = pixel.rgbtGreen;
            float blue = pixel.rgbtBlue;

            // Average the RGB elements and assign it to the pixel
            int average = round((red + green + blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap each pixel with its counterpart on the x-axis
            RGBTRIPLE pixel = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each pixel and create a copy of image with them
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;

            float counter = 0.0;

            // Iterate over the pixel's neighbors
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int ik = i + k;
                    int jl = j + l;

                    // Checking if the 'pixel' is still within the image's boundaries
                    if (ik < 0 || ik > (height - 1) || jl < 0 || jl > (width - 1))
                    {
                        continue; // Not a pixel
                    }

                    RGBTRIPLE pixel = image[ik][jl];

                    // RGB elements of the pixel neighborhood
                    red += pixel.rgbtRed;
                    green += pixel.rgbtGreen;
                    blue += pixel.rgbtBlue;

                    counter++;
                }

                // Add to each copy's pixels the rounded average of its pixel's neighborhood
                copy[i][j].rgbtRed = round(red / counter);
                copy[i][j].rgbtGreen = round(green / counter);
                copy[i][j].rgbtBlue = round(blue / counter);
            }
        }
    }

    // Copy the copy into the original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Gx and Gy from the Sobel's operator
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redX = 0, redY = 0, greenX = 0, greenY = 0, blueX = 0, blueY = 0;

            // Iterate over neighbouring pixels
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    // Check if pixel is within boundaries
                    if (i - 1 + k < 0 || i - 1 + k > height - 1 || j - 1 + l < 0 || j - 1 + l > width - 1)
                    {
                        continue; // It's not
                    }

                    // Calculate Gx
                    redX = redX + (image[i - 1 + k][j - 1 + l].rgbtRed * Gx[k][l]);
                    greenX = greenX + (image[i - 1 + k] [j - 1 + l].rgbtGreen * Gx[k][l]);
                    blueX = blueX + (image[i - 1 + k][j - 1 + l].rgbtBlue * Gx[k][l]);

                    // Calculate Gy
                    redY = redY + (image[i - 1 + k][j - 1 + l].rgbtRed * Gy[k][l]);
                    greenY = greenY + (image[i - 1 + k][j - 1 + l].rgbtGreen * Gy[k][l]);
                    blueY = blueY + (image[i - 1 + k][j - 1 + l].rgbtBlue * Gy[k][l]);
                }
            }

            int red = round(sqrt(pow(redX, 2) + pow(redY, 2)));
            int green = round(sqrt(pow(greenX, 2) + pow(greenY, 2)));
            int blue = round(sqrt(pow(blueX, 2) + pow(blueY, 2)));

            // Cap RGB elements to 255
            copy[i][j].rgbtRed = (red > 255) ? 255 : red;
            copy[i][j].rgbtGreen = (green > 255) ? 255 : green;
            copy[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    // Copy the copy into the original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
