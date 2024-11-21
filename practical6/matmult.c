#include <stdio.h>

#define N 5
#define P 3
#define Q 4

void matmult(double A[N][P], double B[P][Q], double C[N][Q]) {
    // Initialize C to zero
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            C[i][j] = 0;
        }
    }

    // Compute elements of C
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            for (int k = 0; k < P; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
