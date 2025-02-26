#include "helpers.h"
#include "math.h"

#define RED_COLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++ )
        {
            int avg = round(image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / 3.0;
            image[row][col].rgbtRed = image[row][col].rgbtGreen = image[row][col].rgbtBlue = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int sRed = round(0.393 * image[row][col].rgbtRed + 0.769 * image[row][col].rgbtGreen + 0.189 * image[row][col].rgbtBlue);
            int sGreen = round(0.349 * image[row][col].rgbtRed + 0.686 * image[row][col].rgbtGreen + 0.168 * image[row][col].rgbtBlue);
            int sBlue = round(0.272 * image[row][col].rgbtRed + 0.534 * image[row][col].rgbtGreen + 0.131 * image[row][col].rgbtBlue);

            image[row][col].rgbtRed = fmin(255, sRed);
            image[row][col].rgbtGreen = fmin(255, sGreen);
            image[row][col].rgbtBlue = fmin(255, sBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width / 2; column++)
        {
            temp = image[row][column];
            image[row][column]= image[row][width - column - 1];
            image[row][width - column - 1] = temp;
        }
    }
    return;
}

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float count = 0;
    int sum = 0;
    for (int row = i - 1; row <= (i+1); row++)
    {
        for(int column = j - 1; column <= (j+1); column++)
        {
            if(row < 0 || row >= height || column < 0 || column >= width)
            {
                continue;
            }
            if(color_position == RED_COLOR)
            {
                sum += image[row][column].rgbtRed;
            }
            else if(color_position == GREEN_COLOR)
            {
                sum += image[row][column].rgbtGreen;
            }
            else
            {
                sum += image[row][column].rgbtBlue;
            }
            count++;
        }
    }
    return round(sum/count);
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            copy[row][column] = image[row][column];
        }
    }
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            image[row][column].rgbtRed = getBlur(row, column, height, width, copy, RED_COLOR);
            image[row][column].rgbtGreen = getBlur(row, column, height, width, copy, GREEN_COLOR);
            image[row][column].rgbtBlue = getBlur(row, column, height, width, copy, BLUE_COLOR);
        }
    }
    return;
}
