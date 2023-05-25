#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *input_file = fopen(argv[1], "r");
    int size = atoi(argv[2]);
    int num;
    char line[100];
    while (fgets(line, 100, input_file) != NULL)
    {
        int count = 0;
        int sum = 0;
        char *token = strtok(line, " \n");
        while (token != NULL)
        {
            count++;
            if (count > size)
            {
                break;
            }
            sum += atoi(token);
            token = strtok(NULL, " \n");
        }
        if (count == size)
        {
            printf("%d\n", sum);
        }
    }
    fclose(input_file);

    return 0;
}
