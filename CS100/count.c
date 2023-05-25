#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char *str = argv[1];
    int uppers = 0, lowers = 0, digits = 0;

    while (*str != '\0') {
        if (isupper(*str)) {
            uppers++;
        } else if (islower(*str)) {
            lowers++;
        } else if (isdigit(*str)) {
            digits++;
        }
        str++;
    }

    printf("Uppers = %d\n", uppers);
    printf("Lowers = %d\n", lowers);
    printf("Digits = %d\n", digits);

    return 0;
}
