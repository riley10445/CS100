#include <stdio.h>
#include <ctype.h>

int main()
{
    int freq[26] = {0};
    int c;
    printf("Enter your input: \n");
    while ((c = getchar()) != EOF)
    {
        if (islower(c))
        {
            freq[c - 'a']++;
        }
    }
    int all_present = 1;
    printf("Missing letters: ");
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == 0)
        {
            printf("%c ", i + 'a');
            all_present = 0;
        }
    }
    if (all_present)
    {
        printf("Your input contains all the letters\n");
    }
    else
    {
        printf("\n");
    }
    return 0;
}
