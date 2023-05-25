#include <stdio.h>
#include <string.h>

int main()
{
    char string[50 + 1];
    int char_count[128] = {0};

    printf("Enter a string: ");
    scanf("%50s", string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        char_count[(int)string[i]]++;
    }

    int has_unique_char = 0;
    printf("Unique characters include: ");
    for (int i = 0; i < 128; i++)
    {
        if (char_count[i] == 1)
        {
            printf("%c ", (char)i);
            has_unique_char = 1;
        }
    }
    if (has_unique_char == 0)
    {
        printf("NONE");
    }
    printf("\n");

    return 0;
}
