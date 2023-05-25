#include <stdio.h>
#include <ctype.h>
#include <string.h>

void countCase(char str[], int *pNumUpper, int *pNumLower);

int main()
{
    char str[51];
    char words[10][51];
    int numWords = 0;
    fgets(str, 51, stdin);
    char *token = strtok(str, " \n");
    while (token != NULL && numWords < 10)
    {
        strncpy(words[numWords], token, 51);
        numWords++;
        token = strtok(NULL, " \n");
    }
    for (int i = 0; i < numWords; i++)
    {
        int numUpper, numLower;
        countCase(words[i], &numUpper, &numLower);
        printf("%s: %d uppercase, %d lowercase\n", words[i], numUpper, numLower);
    }
    return 0;
}

void countCase(char str[], int *pNumUpper, int *pNumLower)
{
    int i;
    *pNumUpper = 0;
    *pNumLower = 0;
    for (i = 0; str[i] != '\0' && i < 50; i++)
    {
        if (isupper(str[i]))
        {
            (*pNumUpper)++;
        }
        else if (islower(str[i]))
        {
            (*pNumLower)++;
        }
    }
}
