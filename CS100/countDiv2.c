#include <stdio.h>

void countDiv(int arr[], int size, int *refDiv3and5, int *refDiv3, int *refDiv5);

int main()
{
    int size;
    printf("How many numbers:\n");
    scanf("%d", &size);

    int nums[size];
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }

    int div3and5, div3, div5;
    countDiv(nums, size, &div3and5, &div3, &div5);

    printf("%d are divisible by 3 and 5\n", div3and5);
    printf("%d are divisible by 3\n", div3);
    printf("%d are divisible by 5\n", div5);

    return 0;
}

// DO NOT MODIFY ABOVE THIS LINE

void countDiv(int arr[], int size, int *refDiv3and5, int *refDiv3, int *refDiv5)
{
    int n = 0;
    while (n < size)
    {
        if (arr[n] % 5 = 0 and arr[n] % 3 = 0)
        {
            *refDiv3and5 += 1;
        }
        else if (arr[n] % 3 = 0)
        {
            *reDiv3 += 1;
        }
        else if (arr[n] % 5 = 0)
        {
            *refDiv5 += 1;
        }
    }
}
