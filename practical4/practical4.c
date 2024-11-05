#include <stdio.h>
#include <math.h>

#define numberOfValues 13  // Number of values from 0 to 60 degrees, every 5 degrees
float tan_values[numberOfValues];  // Global array

// Function to convert degrees to radians
float convertDegreesToRadians(int degrees) {
    return degrees * (M_PI / 180.0f);
}

float trap() {
    float a = convertDegreesToRadians(0);     // Start point in radians
    float b = convertDegreesToRadians(60);    // End point in radians
    int N = numberOfValues - 1;              // Number of intervals
    float h = (b - a) / N;               // Width of each interval
    float sum = tan(a) + tan(b);         // First and last terms of the sum

    // Sum of the middle terms with 2 * tan(x_i)
    for (int i = 1; i < N; i++) {
        float x_i = a + i * h;
        sum += 2 * tan(x_i);
    }

    // Multiply by (b - a) / (2 * N) to get the integral approximation
    return (b - a) * sum / (2 * N);
}

int main() {
    // Populate the tan_values array with tan(x) values every 5 degrees
    for (int i = 0; i < numberOfValues; i++) {
        int angle = i * 5;  // Generate angle in degrees (0, 5, ..., 60)
        float radians = convertDegreesToRadians(angle);  // Convert to radians
        tan_values[i] = tan(radians);  // Compute tan(x) and store in array
    }

    // Print the tan(x) values
    printf("Tan(x) values (in radians) for every 5 degrees from 0 to 60:\n");
    for (int i = 0; i < numberOfValues; i++) {
        printf("tan(%d degrees) = %f\n", i * 5, tan_values[i]);
    }

    // Calculate and print the integral using the trapezoidal rule
    float integral_result = trap();
    printf("\nApproximate integral of tan(x) from 0 to 60 degrees: %f\n", integral_result);

    return 0;
}
