#include <stdio.h>


int main(void) {
   int i;
   float sum1, sum2, diff;
   

/* First sum */
   sum1 = 0.0;
   for (i=1; i<=1000; i++) {
      sum1 = sum1 + (1.00000/i);
   }


/* Second sum */
   sum2 = 0.0;
   for (i=1000; i>0; i--) {
      sum2 = sum2 + (1.00000/i);
   }

   printf(" Sum1=%.5f\n",sum1);
   printf(" Sum2=%.5f\n",sum2);

/* Find the difference */
   diff = sum2-sum1;

   printf(" Difference between the two is %.5f\n",diff);

}
