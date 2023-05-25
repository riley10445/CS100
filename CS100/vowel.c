#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    char words[50];

    scanf("%[^\n]s", words);
    for (int j = 0; j < strlen(words); j++)
    {
        if (words[j] == ' ')
        {
            continue;
        }
        else if (words[j] == 'a')
        {
            a += 1;
        }
        else if (words[j] == 'e')
        {
            e += 1;
        }
        else if (words[j] == 'i')
        {
            i += 1;
        }
        else if (words[j] == 'o')
        {
            o += 1;
        }
        else if (words[j] == 'u')
        {
            u += 1;
        }
    }

    printf("The vowel a occurred %d times\n", a);
    printf("The vowel e occurred %d times\n", e);
    printf("The vowel i occurred %d times\n", i);
    printf("The vowel o occurred %d times\n", o);
    printf("The vowel u occurred %d times\n", u);

    return 0;
}
