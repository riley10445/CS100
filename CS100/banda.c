#include <stdio.h>

int main()
{
    double x[100];
    int n = 0;
    while (scanf("%lf", &x[n]) == 1)
    {
        n++;
    }
    int numBelow = 0;
    int numAbove = 0;
    double avg = average(n, x, &numBelow, &numAbove);
    printf("Average: %.2f\n", avg);
    printf("Number below average: %d\n", numBelow);
    printf("Number above average: %d\n", numAbove);
    return 0;
}

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