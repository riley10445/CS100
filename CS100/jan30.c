#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // int sum = 0;
    // for (int x=2; x<6; x++)
    // {
    //     sum = sum + x;
    // }
    // printf("%d\n", sum);

    // int num = 2018, val;
    // while (num>0)
    // {
    //     val = num % 10;
    //     printf("%d\n", val);
    //     num = num / 10;
    // }
    // return 0;
    char str1[10], str2[10];
    scanf("%s", str1);
    scanf("%s", str2);
    int len = strlen(str1);
    printf("%d\n", len);
    int num1 = 0, num2 = 0;
    for (int x = 0; x < len; x++)
    {
        if (str1[x] == str2[x])
        {
            num1++;
        }
        else
        {
            num2++;
        }
    }
    printf("%d and %d\n", num1, num2);
}