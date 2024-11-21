#include <stdio.h>

// Checks if a matrix is a magic square
int isMagicSquare(int **square, const int n) {
    
    // Ignore if n is negative
    if (n <= 0) {
        return 0;
    }

    // declare M
    int M = (n * (n * n + 1)) / 2;

    // Check sums of rows and columns
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j]; // Sum of row i
            colSum += square[j][i]; // Sum of column i
        }
        if (rowSum != M || colSum != M) {
            return 0; // Not a magic square
        }
    }

    // Check sum of the main diagonal
    int mainDiagSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagSum += square[i][i];
    }
    if (mainDiagSum != M) {
        return 0; // Not a magic square
    }

    // Check sum of the secondary diagonal
    int secDiagSum = 0;
    for (int i = 0; i < n; i++) {
        secDiagSum += square[i][n - i - 1];
    }
    if (secDiagSum != M) {
        return 0; // Not a magic square
    }

    // Passed all checks, it is a magic square
    return 1;
}
