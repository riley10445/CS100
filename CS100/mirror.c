#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000 // maximum input length

int main() {
    char input[MAX_LEN];
    int width;
    int len, i, j, k, line;

    printf("Enter the width of an output line: ");
    scanf("%d", &width);

    printf("Enter your text (control-d to exit):");
    while (fgets(input, MAX_LEN, stdin) != NULL) {
        len = strlen(input);

        // Remove newline character at end of input
        if (input[len-1] == '\n') {
            input[len-1] = '\0';
            len--;
        }

        for (i = len - 1; i >= 0; i -= width) {
            line = i - width + 1;
            if (line < 0) {
                line = 0;
            }

            // Calculate number of spaces needed for right alignment
            int num_spaces = width - (i - line + 1);

            // Print spaces before each line to right-align it
            for (j = 0; j < num_spaces; j++) {
                putchar(' ');
            }

            for (j = width - 1; j >= 0; j--) {
                k = line + j;
                if (k < len) {
                    putchar(input[k]);
                } else {
                    putchar(' ');
                }
            }

            putchar('\n');
        }
        printf("\n");

    }

    return 0;
}
