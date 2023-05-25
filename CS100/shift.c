#include <stdio.h>

void shift(int *a, int *b, int *c)
{
    int orig = *a;
    *a = *c;
    *c = *b;
    *b = orig;
}

int main()
{
    int a, b, c;

    printf("Enter any three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    shift(&a, &b, &c);
    printf("The results after one shift: %d %d %d\n", a, b, c);

    shift(&a, &b, &c);
    printf("The results after another shift: %d %d %d\n", a, b, c);

    return 0;
}
