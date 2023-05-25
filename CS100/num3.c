#include <stdio.h>

int main()
{
    int numbers[50];
    int num;
    int i = 0;

    while (scanf("%d", &num) == 1 && num != 0)
    {
        numbers[i] = num;
        i++;
    }

    for (int j = 0; j <= i; j++)
    {
        num = numbers[j];
        if (num >= 1000 && num <= 9999)
        {
            num /= 10;
            num = num % 10;
            printf("%d", num);
        }
        else
        {
            continue;
        }
    }
    printf("\n");

    return 0;
}