#include <stdio.h>

void countDiv(int arr[], int size, int *refDiv3and5, int *refDiv3, int *refDiv5);

int main() {
   int size;
   printf("How many numbers:\n");
   scanf("%d", &size);
   
   int nums[size];
   printf("Enter %d numbers:\n", size);
   for (int i = 0; i < size; i++) {
      scanf("%d", &nums[i]);
   }
   
   int div3and5, div3, div5;
   countDiv(nums, size, &div3and5, &div3, &div5);
   
   printf("%d are divisible by 3 and 5\n", div3and5);
   printf("%d are divisible by 3\n", div3);
   printf("%d are divisible by 5\n", div5);

   return 0;
}

void countDiv(int arr[], int size, int *refDiv3and5, int *refDiv3, int *refDiv5) {
   int countDiv3and5 = 0, countDiv3 = 0, countDiv5 = 0;
   
   for (int i = 0; i < size; i++) {
      if (arr[i] % 3 == 0 && arr[i] % 5 == 0) {
         countDiv3and5++;
      }
      else if (arr[i] % 3 == 0) {
         countDiv3++;
      }
      else if (arr[i] % 5 == 0) {
         countDiv5++;
      }
   }
   
   *refDiv3and5 = countDiv3and5;
   *refDiv3 = countDiv3;
   *refDiv5 = countDiv5;
}
