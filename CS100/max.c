#include <stdio.h>

int main() {
    int arr[10] = {12, 45, 67, 3, 89, 56, 23, 90, 34, 78};
    int *ptr;
    int max = 0;
    
    ptr = arr;
    
    for(int i=0; i<10; i++) {
        if(*ptr > max) {
            max = *ptr;
        }
        ptr++;
    }
    
    printf("Largest: %d", max);
}