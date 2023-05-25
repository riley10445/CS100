#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double totalPay(double rate, int hours)
{
    double pay;
    if (hours <= 40)
    {
        pay = rate * hours;
    }
    else if (hours <= 50)
    {
        pay = rate * 40 + (rate * 1.5 * (hours - 40));
    }
    else
    {
        pay = rate * 40 + (rate * 1.5 * 10) + (rate * 2 * (hours - 50));
    }
    return pay;
}

int main()
{
    int hours;
    double rate;
    double pay = 0.0;

    scanf("%lf %d", &rate, &hours);

    pay = totalPay(rate, hours);

    printf("$%lf\n", pay);

    return 0;
}
