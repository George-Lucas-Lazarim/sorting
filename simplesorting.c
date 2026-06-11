#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubblesort.h"
#include "mergesort.h"
#include "quicksort.h"

#define SIZE 100000

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int* messyArray = (int*) malloc (SIZE * sizeof(int));
    int* bubbleArray = (int*) malloc (SIZE * sizeof(int));
    int* mergeArrayBottomUp = (int*) malloc (SIZE * sizeof(int));
    int* mergeArrayTopDown = (int*) malloc (SIZE * sizeof(int));
    int* quickArray = (int*) malloc (SIZE * sizeof(int));

    if (messyArray == NULL || bubbleArray == NULL || mergeArrayBottomUp == NULL || mergeArrayTopDown == NULL || quickArray == NULL) {
        printf("\nError! Failed to allocate memory");
        return 1;
    }

    printf("Generating %d random numbers...\n", SIZE);

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        messyArray[i] = rand() % 100000;
        bubbleArray[i] = mergeArrayBottomUp[i] = mergeArrayTopDown[i] = quickArray[i] = messyArray[i];
    }

    clock_t start, end;
    double timeSpent;

    /*
    printf("\nThe generated random array: ");
    printArray(messyArray, SIZE);
    */

    printf("\n=== Starting speed test ===");

    start = clock();
    bubbleSort(bubbleArray, SIZE);
    end = clock();

    timeSpent = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime spent sorting an array using the bubble sort algorithm: %f seconds ", timeSpent);

    // printArray(bubbleArray, SIZE);

    start = clock();
    mergeSortBottomUp(mergeArrayBottomUp, SIZE);
    end = clock();

    timeSpent = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime spent sorting an array using the merge sort bottom up algorithm: %f seconds ", timeSpent);

    // printArray(mergeArrayBottomUp, SIZE);

    start = clock();
    mergeSortTopDown(mergeArrayTopDown, 0, SIZE - 1);
    end = clock();

    timeSpent = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime spent sorting an array using the merge sort top down algorithm: %f seconds ", timeSpent);

    // printArray(mergeArrayTopDown, SIZE);

    start = clock();
    quickSort(quickArray, 0, SIZE - 1);
    end = clock();

    timeSpent = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime spent sorting an array using the quick sort algorithm: %f seconds ", timeSpent);

    // printArray(quickArray, SIZE);

    free(messyArray);
    free(bubbleArray);
    free(mergeArrayBottomUp);
    free(mergeArrayTopDown);
    free(quickArray);

    printf("\n");
}