#include <stdio.h>

int main() {
    int number, digit;
    int digit_counts[10] = {0};

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 0) {
        digit = number % 10;
        digit_counts[digit]++;
        number /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (digit_counts[i] > 1) {
            printf("Duplicate digits found\n");
            return 0;
        }
    }

    printf("No duplicate digits found\n");
    return 0;
}
