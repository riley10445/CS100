#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 200

int main()
{
    char word[MAX_WORD_LEN + 1];
    char words[MAX_WORDS][MAX_LINE_LEN + 1];
    int num_words = 0;
    int num_removed = 0;
    int num_spaces = 0;
    int num_newlines = 0;

    printf("--NEW TEXT--\n");
    fgets(words[num_words], MAX_LINE_LEN + 1, stdin);
    num_words++;

    while (fgets(words[num_words], MAX_LINE_LEN + 1, stdin) != NULL)
    {
        char *ptr = words[num_words];
        num_words++;

        while (*ptr != '\0')
        {
            if (*ptr == ' ')
            {
                num_spaces++;
            }
            else if (*ptr == '\n')
            {
                num_newlines++;
            }
            ptr++;
        }
    }

    scanf("%s", word);

    for (int i = 0; i < num_words; i++)
    {
        char *ptr = words[i];
        while (*ptr != '\0')
        {
            if (strncmp(ptr, word, strlen(word)) == 0 && (!isalnum(*(ptr + strlen(word))) && isspace(*(ptr + strlen(word)))))
            {
                num_removed++;
                ptr += strlen(word);
                while (*ptr == ' ')
                {
                    ptr++;
                }
            }
            else
            {
                printf("%c", *ptr);
                ptr++;
            }
        }
    }
    printf("--STATS--\n");
    printf("Number of words in the original text: %d\n", num_spaces + num_newlines);
    printf("Number of words removed: %d\n", num_removed);

    return 0;
}
