#include <stdio.h>

int median(int a, int b, int c);

int main(void) {
   int a, b, c;
   while (3 == scanf("%d%d%d", &a, &b, &c)) {
      printf("median of %d, %d, and %d is %d\n", a, b, c, median(a, b, c)); 
   }
   return 0;
}

int median(int a, int b, int c) {
   if ((a <= b && b <= c) || (c <= b && b <= a)) {
      return b;
   } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
      return a;
   } else {
      return c;
   }
}
