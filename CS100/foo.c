#include <stdio.h>

void foo(int n, int x[], int threshold, int *pChanged, int *pUnchanged);

int main()
{

    int threshold;
    printf("What is the threshold?\n");
    scanf("%d", &threshold);

    int n;
    printf("How many integers?\n");
    scanf("%d", &n);

    int x[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    int changed = -100, unchanged = -100;
    foo(n, x, threshold, &changed, &unchanged);

    printf("The array is now:\n[");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", x[i]);
    }
    printf(" ]\n");
    printf("%d were changed\n", changed);
    printf("%d were unchanged\n", unchanged);

    return 0;
}

void foo(int n, int x[], int threshold, int *pChanged, int *pUnchanged)
{
    int changed = 0;
    int unchanged = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < threshold)
        {
            x[i] *= 2;
            changed++;
        }
        else
        {
            unchanged++;
        }
    }
    *pChanged = changed;
    *pUnchanged = unchanged;
}