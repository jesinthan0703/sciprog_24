#include <stdio.h>

#define N 5
#define P 3
#define Q 4

void matmult(double A[N][P], double B[P][Q], double C[N][Q]);

int main() {

    // Declare Matrix arrays
    double A[N][P], B[P][Q], C[N][Q];

    int i, j;

    // Initialize Matrix A
    for (i = 0; i < N; i++) {
        for (j = 0; j < P; j++) {
            A[i][j] = i + j;  // Ai,j = i + j
        }
    }

    // Initialize Matrix B
    for (i = 0; i < P; i++) {
        for (j = 0; j < Q; j++) {
            B[i][j] = i - j;  // Bi,j = i - j
        }
    }

    // Call matmult to compute C
    matmult(A, B, C);

    // Print Matrix A
    printf("Matrix A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < P; j++) {
            printf("%.2lf ", A[i][j]);
        }
        printf("\n");
    }

    // Print Matrix B
    printf("\nMatrix B:\n");
    for (i = 0; i < P; i++) {
        for (j = 0; j < Q; j++) {
            printf("%.2lf ", B[i][j]);
        }
        printf("\n");
    }

    // Print Matrix C
    printf("\nMatrix C:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < Q; j++) {
            printf("%.2lf ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
