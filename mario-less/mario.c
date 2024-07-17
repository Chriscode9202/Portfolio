# include <stdio.h>
# include <cs50.h>


int main (void)
{
    int height, line, column, space;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (line = 0; line < height; line++)
    {
        for (space = 0; space < height - line - 1; space ++)
        {
            printf(" ");
        }
        for (column = 0; column <= line; column++)
        {
            printf("#");
        }
             printf("\n");
    }
}