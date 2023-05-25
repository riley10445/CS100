#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double max = -10000;
    double min = 10000;

    if (argc < 2)
    {
        printf("This program requires at least one argument\n");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        double num = atof(argv[i]);

        if (num > max)
        {
            max = num;
        }

        if (num < min)
        {
            min = num;
        }
    }

    double range = max - min;

    printf("The range of these %d values is %.6f\n", argc - 1, range);

    return 0;
}