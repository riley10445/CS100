#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char str1[20];
    char str2[20];

    int lower1_count = 0;
    int lower2_count = 0;

    printf("Enter two strings: \n");
    scanf("%s", str1);
    scanf("%s", str2);

    for (int i = 0; i < 10; i++)
    {
        if (islower(str1[i]))
        {
            lower1_count += 1;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (islower(str2[i]))
        {
            lower2_count += 1;
        }
        else
        {
            break;
        }
    }

    if (lower1_count > lower2_count)
    {
        printf("'%s' contains %d more lowercase letter(s) than '%s'.", str1, lower1_count - lower2_count, str2);
    }
    if (lower1_count == lower2_count)
    {
        printf("'%s' and '%s' both contain %d lowercase letter(s).", str1, str2, lower1_count);
    }
    if (lower1_count < lower2_count)
    {
        printf("'%s' contains %d more lowercase letter(s) than '%s'.", str2, lower2_count - lower1_count, str1);
    }

    return 0;
}