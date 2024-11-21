#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square_stub.h"

// Function to count the number of lines in a file
int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int ch_read;
    int count = 0;

    while ((ch_read = fgetc(fp)) != EOF) {
        if (ch_read == '\n') {
            count++;
        }
    }

    fclose(fp);
    return count;
}

int main() {
    FILE *f;
    char filename[MAX_FILE_NAME];

    // get file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Get the number of lines (n) from the file
    int n = getlines(filename);
    if (n <= 0) {
        printf("Invalid or empty file.\n");
        return 1;
    }

    // Open the file for reading
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Allocate memory for the matrix
    int **square = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        square[i] = (int *)malloc(n * sizeof(int));
    }

    // Read the matrix from the file
    printf("Reading matrix from file:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &square[i][j]);
            printf("%d ", square[i][j]); // Display the matrix for confirmation
        }
        printf("\n");
    }

    // Check if the matrix is a magic square
    if (isMagicSquare(square, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is NOT a magic square.\n");
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(square[i]);
    }
    free(square);

    // Close the file
    fclose(f);

    return 0;
}
