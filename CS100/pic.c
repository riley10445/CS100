#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int rows;
    int i, j;
    scanf("%d", &rows);
    int columns = rows;

    for (i = 0; i < columns; i++)
    {
        if (i == 0 || i == rows - 1)
        {
            for (j = 0; j < columns; j++)
            {
                printf("X");
            }
        }
        else
        {
            printf("X");
            for (j = 0; j < rows - 2; j++)
            {
                printf(" ");
            }
            printf("X");
        }
        printf("\n");
    }

    return 0;
}