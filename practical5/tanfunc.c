#include <stdio.h>
#include <math.h>

#define DELTA 1e-10 // Precision for the Maclaurin series (can be adjusted)

// Function to approximate arctanh(x) using the Maclaurin series
double arctanh1(double x, double delta) {
    double term = x; // First term x^(2n+1)/(2n+1) with n=0
    double sum = term;
    int n = 1;

    // Continue adding terms until the current term is smaller than the precision delta
    while (fabs(term) > delta) {
        term = pow(x, 2 * n + 1) / (2 * n + 1);
        sum += term;
        n++;
    }
    
    return sum;
}

// Function to calculate arctanh(x) using natural logarithms
double arctanh2(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}

int main() {
    double delta = DELTA;
    double x, result1, result2;

    // Define the range of x and step size for sampling
    double start = -0.9;
    double end = 0.9;
    double step = 0.01;

    // Arrays to store results from both methods
    double results_maclaurin[181]; // Store arctanh1 results
    double results_logarithm[181]; // Store arctanh2 results
    int index = 0;

    printf(" x\t\tarctanh1 (Maclaurin)\tarctanh2 (Logarithm)\n");
    printf("----------------------------------------------------------\n");

    // Loop through x from -0.9 to 0.9 with a step of 0.01
    for (x = start; x <= end; x += step) {
        // Calculate arctanh(x) using both methods
        result1 = arctanh1(x, delta);
        result2 = arctanh2(x);

        // Store the results
        results_maclaurin[index] = result1;
        results_logarithm[index] = result2;

        // Print results to 10 significant figures
        printf("% .2f\t%.10f\t%.10f\n", x, result1, result2);

        index++;
    }

    // Comparison of results (optional)
    printf("\nComparison (to 10 significant figures):\n");
    for (int i = 0; i < index; i++) {
        printf(" x = %.2f: arctanh1 = %.10f, arctanh2 = %.10f, Difference = %.10f\n",
               start + i * step, results_maclaurin[i], results_logarithm[i],
               fabs(results_maclaurin[i] - results_logarithm[i]));
    }

    return 0;
}
