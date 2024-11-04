#include <stdio.h>
#include <math.h>

int main() {
    float a = 0;
    float b = M_PI / 3.0;

    int N = 12;

    float h = (b - a) / N;
    float sum = 0;

    // Calculate the first and last terms of the trapezoidal sum
    sum += tan(a) + tan(b);

    // Loop to add 2 * tan(x_i) for the inner points
    int i;
    for (i = 1; i < N; i++) {
        float x_i = a + i * h;
        sum += 2 * tan(x_i);
    }

    // Multiply by (b - a) / (2 * N) to complete the trapezoidal rule
    double result = (b - a) * sum / (2 * N);

    printf("Approximate integral of tan(x) from 0 to pi/3 is: %f\n", result);
    printf("Actual result (log(2)) is approximately: %f\n", log(2));
    printf("The difference is : %f", (result-log(2)));

    return 0;
}
