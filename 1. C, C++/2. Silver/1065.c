#include <stdio.h>

void hansoo(int n) {
   int a, b, c, i;
   if (n < 100)
      printf("%d", n);
   else{
       int num = 99;

       for (i = 100; i <= n; i++) {
          a = i / 100;
          b = (i%100) / 10;
          c = (i%100)%10;

          if ((c - b) == (b - a))
             num++;
       }
       printf("%d", num);
   }
}

int main() {
   int n;
   scanf("%d", &n);
   hansoo(n);
}