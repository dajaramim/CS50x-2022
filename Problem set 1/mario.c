#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // beetween 1 or 8, otherwise the loop will continue
    while (n < 1);

    // For each row
    for (int i = 0; i < n; i++)
    {
        // for each column
        for (int j = 0; j < n; j++)
        {
            // Print a brick
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        //right pyramid 
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("\n");
    }
}
