#include <stdio.h>

// Recursive logic
int gcdRecursive(int a, int b) {

    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

int main() {
    int a, b;

    // Input two integers
    printf("Enter first integer : ");
    scanf("%d", &a);
    printf("Enter second integer : ");
    scanf("%d", &b);

    // Calculate and print the GCD
    printf("The GCD of %d and %d is: %d\n", a, b, gcdRecursive(a, b));

    return 0;
}
