#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAX_INPUT_LEN 1000

void align_right(char input[], int width);
void align_center(char input[], int width);
void align_left(char input[]);

int main()
{
    char input[MAX_INPUT_LEN];
    int width;
    char alignment[10];
    char autocorrect_str[5];
    int autocorrect = 0;

    printf("Input: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    printf("Column width: ");
    scanf("%d", &width);
    printf("Alignment: ");
    scanf("%s", alignment);
    printf("Autocorrect: ");
    scanf("%s", autocorrect_str);
    if (strcmp(autocorrect_str, "yes") == 0)
    {
        autocorrect = 1;
    }
    input[strcspn(input, "\n")] = '\0';

    int len = strlen(input);
    if (width < len)
    {
        printf("Invalid column width\n");
        exit(0);
    }
    int num_words = 1;
    float avg_word_len = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(input[i]))
        {
            avg_word_len += 1;
        }
        if (input[i] == ' ')
        {
            num_words++;
        }
    }
    avg_word_len /= num_words;

    if (autocorrect)
    {
        int in_sentence = 1;
        for (int i = 0; i < len; i++)
        {
            if (in_sentence && isalpha(input[i]))
            {
                input[i] = toupper(input[i]);
                in_sentence = 0;
            }
            else if (input[i] == '.' && i + 2 < len && isspace(input[i + 1]))
            {
                input[i + 2] = toupper(input[i + 2]);
                in_sentence = 0;
            }
            if (input[i] == '3')
            {
                input[i] = 'e';
            }
            else if (input[i] == '1')
            {
                input[i] = 'l';
            }
            else if (input[i] == '0')
            {
                input[i] = 'o';
            }
            else if (input[i] == '7')
            {
                input[i] = 't';
            }
            if (input[i] == '.' && i + 1 < len && isspace(input[i + 1]))
            {
                in_sentence = 1;
            }
            if (i == len - 1 && i != '.')
            {
                input[i + 1] = '.';
            }
        }
        input[0] = toupper(input[0]);
    }

    int j = 0;
    while (j < width)
    {
        printf("-");
        j++;
    }
    printf("\n");

    if (strcmp(alignment, "right") == 0)
    {
        align_right(input, width);
    }
    if (strcmp(alignment, "center") == 0)
    {
        align_center(input, width);
    }
    if (strcmp(alignment, "left") == 0)
    {
        align_left(input);
    }
    printf("Words: %d\n", num_words);
    printf("Avg word length: %f\n", avg_word_len);
}

void align_left(char input[])
{
    printf("%s\n", input);
}

void align_right(char input[], int width)
{
    int difference = width - strlen(input);
    for (int i = 0; i < difference; i++)
    {
        printf(" ");
    }
    printf("%s", input);
    printf("\n");
}

void align_center(char input[], int width)
{
    float difference = (width - strlen(input)) / 2.0;
    int rounded = round(difference);
    for (int i = 0; i < difference; i++)
    {
        printf(" ");
    }
    printf("%s\n", input);
}