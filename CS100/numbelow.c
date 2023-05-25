#include <stdio.h>

double average(int n, double x[], int *pNumBelow, int *pNumAbove)
{
    double avg = 0.0;
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += x[i];
    }
    avg = sum / n;

    int numBelow = 0;
    int numAbove = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < avg)
            numBelow++;
        else if (x[i] > avg)
            numAbove++;
    }
    *pNumBelow = numBelow;
    *pNumAbove = numAbove;
    return avg;
}

int main()
{
    int n;
    int numBelow, numAbove = 0;
    double x[20];
    printf("How many numbers?\n");
    scanf("%d", &n);
    printf("Enter %d numbers-\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    double avg = average(n, x, &numBelow, &numAbove);
    printf("Average- %.2lf\nBelow average- %d\nAbove average- %d\n", avg, numBelow, numAbove);

    return 0;
}
