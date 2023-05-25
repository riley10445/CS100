#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Cannot open file '%s'\n", argv[1]);
        return 0;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        printf("Cannot open file '%s'\n", argv[2]);
        fclose(input_file);
        return 0;
    }

    char str[51];
    while (fscanf(input_file, "%50s", str) == 1)
    {
        int is_all_letters = 1;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (!isalpha(str[i]))
            {
                is_all_letters = 0;
                break;
            }
        }
        if (is_all_letters)
        {
            fprintf(output_file, "%s\n", str);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
