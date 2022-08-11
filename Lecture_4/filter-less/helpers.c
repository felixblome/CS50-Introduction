#include "helpers.h"
#include <math.h>
#include <stdio.h>

#define BLUR 3

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for(int h = 0; h < height; h++) {
        for(int w = 0; w < width; w++) {
            // n calculates the average value of all pixel colors
            float n = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3.0);
            // assign the value to all pixels
            image[h][w].rgbtBlue = n;
            image[h][w].rgbtGreen = n;
            image[h][w].rgbtRed = n;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
    for(int h = 0; h < height; h++) {
        for(int w = 0; w < width; w++) {
            // store original values for each iteration
            float orgRed = image[h][w].rgbtRed;
            float orgGreen = image[h][w].rgbtGreen;
            float orgBlue = image[h][w].rgbtBlue;
            // calculate new sepia color with previous stored original values of each pixel
            float sepiaRed = round(.393 * orgRed + .769 * orgGreen + .189 * orgBlue);
            float sepiaGreen = round(.349 * orgRed + .686 * orgGreen + .168 * orgBlue);
            float sepiaBlue = round(.272 * orgRed + .534 * orgGreen + .131 * orgBlue);
            // cap max. value at 255
            if(sepiaRed >= 256) {
                sepiaRed = 255;
            }
            if(sepiaGreen >= 256) {
                sepiaGreen = 255;
            }
            if(sepiaBlue >= 256) {
                sepiaBlue = 255;
            }
            // set each pixel to the new calculated sepia color
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    for(int h = 0; h < height; h++) {
        for(int w = 0; w < (width / 2); w++) {
            float orgRed = image[h][w].rgbtRed;
            float orgGreen = image[h][w].rgbtGreen;
            float orgBlue = image[h][w].rgbtBlue;

            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;

            image[h][width - w - 1].rgbtRed = orgRed;
            image[h][width - w - 1].rgbtGreen = orgGreen;
            image[h][width - w - 1].rgbtBlue = orgBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE newPixel[height][width];
    float avgRed, avgGreen, avgBlue;
    int counter;
    for(int h = 0; h < height; h++) {
        for(int w = 0; w < width; w++) {
            avgRed = avgGreen = avgBlue = counter = 0;
            for(int rows = h - ((BLUR - 1) / 2); rows <= h + ((BLUR - 1) / 2); rows++) {
                for(int cols = w - ((BLUR - 1) / 2); cols <= w + ((BLUR - 1) / 2); cols++) {
                    if ((rows >= 0 && rows < height) && (cols >= 0 && cols < width)) {
                        avgRed += image[rows][cols].rgbtRed;
                        avgGreen += image[rows][cols].rgbtGreen;
                        avgBlue += image[rows][cols].rgbtBlue;
                        counter++;
                    }
                }
            }
            if(counter != 0) {
                avgRed = round(avgRed / (double) counter);
                avgGreen = round(avgGreen / (double) counter);
                avgBlue = round(avgBlue / (double) counter);
                newPixel[h][w].rgbtRed = avgRed;
                newPixel[h][w].rgbtGreen = avgGreen;
                newPixel[h][w].rgbtBlue = avgBlue;
            }
            else {
                return;
            }
        }
    }
    for(int h = 0; h < height; h++) {
        for(int w = 0; w < width; w++) {
            image[h][w] = newPixel[h][w];
        }
    }
}
