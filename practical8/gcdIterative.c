#include <stdio.h>

// Iterative Logic
int gcdIterative(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;

    // Input two integers
    printf("Enter first integer: ");
    scanf("%d", &a);
    printf("Enter Second integer : ");
    scanf("%d", &b);

    // Calculate and print the GCD
    printf("The GCD of %d and %d is: %d\n", a, b, gcdIterative(a, b));

    return 0;
}
