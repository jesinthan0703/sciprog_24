
#include <stdio.h>

int main(void) {
   int num1, num2;

   printf("Please input two positive integers\n");
   scanf("%d %d", &num1, &num2);
   
   if(num1%2 == 0){
      printf("%d is even\n", num1);
   }
   else {
      printf("%d is odd\n", num1);
   }

   if(num2%2 == 0){
      printf("%d is even\n", num2);
   }
   else {
      printf("%d is odd\n", num2);
   }

  return 0;
}



