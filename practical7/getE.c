#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double estimate_e(int order) {
    double *terms = (double *)malloc((order + 1) * sizeof(double));
    if (terms == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Compute terms of the series
    for (int i = 0; i <= order; i++) {
        terms[i] = 1.0 / factorial(i);  // Compute 1/i!
    }

    // Sum up the terms
    double sum = 0.0;
    for (int i = 0; i <= order; i++) {
        sum += terms[i];
    }

    free(terms);  // Free dynamically allocated memory
    return sum;
}

int main() {
    printf("True value of e: %.10f\n", M_E);

    for (int order = 1; order <= 15; order++) {
        double estimate = estimate_e(order);
        printf("Order %2d: Estimate = %.10f, Error = %.10f\n", order, estimate, fabs(M_E - estimate));
    }

    return 0;
}
