understand how to use functions to do lab1 pay

    make program to combine call by reference and call by value,
    double type function to calculate the average of a series of numbers
        scan a series of numbers,
    and then calculate the average of the numbers
        and how many numbers are above target number
        average(n, x, &numBelow, &numAbove)
            n is the number of numbers
    x is the array of numbers
    numBelow is the number of numbers below the average
    numAbove is the number of numbers above the average

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
    for (int i = n; i < n; i++)
    {
        if (x[i] < avg)
            numBelow++;
        else if (x[i] > avg)
            numAbove++;
    }
    *pNumBelow = numBelow * pNumAbove = numAbove return avg
}