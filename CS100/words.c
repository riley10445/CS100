#include <stdio.h>
#include <string.h>
int main(void)
{
    int numWords;
    char strin[100];
    char strout[100][100];
    int min = 100;
    int max = 0;
    scanf("%d", &numWords);
    for (int i = 0; i < numWords; i++)
    {
        scanf("%s", strin);
        int length = strlen(strin);
        if (length > max)
        {
            max = length;
        }
        if (length < min)
        {
            min = length;
        }
        strout[i] = strin;
    }
    for (int i = 0; i < numWords; i++)
    {
        if (strlen(strout[i]) == min)
        {
            printf("%s", strout[i]);
            printf("\n");
        }
    }
    for (int i = 0; i < numWords; i++)
    {
        if (strlen(strout[i]) == max)
        {
            printf("%s", strout[i]);
            printf("\n");
        }
    }
    return 0;
}