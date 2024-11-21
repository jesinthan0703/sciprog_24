#include <stdio.h>
#include <stdlib.h>

int i;

// Allocate memory to an array
int* allocateArray(int n) {
    int *arr = (int*)malloc(n * sizeof(int));  // Dynamically allocate memory
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return arr;
}

// Fill array with ones
void fillWithOnes(int *arr, int n) {
    for (i = 0; i < n; i++) {
        arr[i] = 1;  // Set each element to 1
    }
}

// Print the array
void printArray(int *arr, int n) {
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Print each element
    }
    printf("\n");
}

// Function to free the allocated memory
void freeMemory(int *arr) {
    free(arr);  // Free the allocated memory
    printf("Memory freed successfully!\n");
}

int main() {
    int n;
    
    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = allocateArray(n);

    // Fill the array with ones
    fillWithOnes(arr, n);

    // Print the array
    printf("Array elements: ");
    printArray(arr, n);

    // Free the allocated memory
    freeMemory(arr);

    return 0;
}
