#include <stdio.h>
#include <stdlib.h>

void fibo(int *a, int *b);

int main(void) {
    int n, a = 0, b = 1;

    printf("Enter value for n (must be greater than 1): \n");
    scanf("%d", &n);

    if (n < 1) {
        printf("The value of n is less than 1. Hence cannot create Fibonacci series!\n");
        exit(1);
    }

    printf("Fibonacci series up to %d terms:\n", n);
    printf("%d %d ", a, b);  // Print the first two terms

    for (int i = 3; i <= n; i++) {  // Start loop from the 3rd term
        fibo(&a, &b);                // Update the values of a and b
        printf("%d ", b);            // Print the next term
    }
    printf("\n");

    return 0;
}

void fibo(int *a, int *b) {
    int temp = *a + *b;
    *a = *b;
    *b = temp;
}
