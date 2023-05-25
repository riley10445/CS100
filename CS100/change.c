#include <stdio.h>

void getChange(int centValue, int *numQuarters, int *numDimes, int *numPennies)
{
    *numQuarters = centValue / 25;
    centValue = centValue % 25;
    *numDimes = centValue / 10;
    centValue = centValue % 10;
    *numPennies = centValue;
}

int main()
{
    int centValue;
    while (scanf("%d", &centValue), centValue != 0)
    {
        int numQuarters, numDimes, numPennies;
        getChange(centValue, &numQuarters, &numDimes, &numPennies);
        printf("%d quarters, %d dimes, %d pennies\n", numQuarters, numDimes, numPennies);
    }
    return 0;
}