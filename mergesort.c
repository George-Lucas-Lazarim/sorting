#include "mergesort.h"

void merge (int array[], int f, int mid, int l) {
    int size = l - f + 1;

    int auxArray[size];

    int i = f;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= l) {
        if (array[i] < array[j]) {
            auxArray[k] = array[i];
            i++;
        } else {
            auxArray[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        auxArray[k] = array[i];
        i++;
        k++;
    }

    while (j <= l) {
        auxArray[k] = array[j];
        j++;
        k++;
    }
    
    for (int i = 0; i < size; i++) array[f + i] = auxArray[i];
}

void mergeSortTopDown (int array[], int f, int l) {
    if (f >= l) return;

    int mid = f + (l - f) / 2;

    mergeSortTopDown(array, f, mid);
    mergeSortTopDown(array, mid + 1, l);

    merge(array, f, mid, l);
}

void mergeSortBottomUp (int array[], int size) {
    for (int currSize = 1; currSize < size; currSize *= 2) {
        for (int leftStart = 0; leftStart < size - 1; leftStart += 2 * currSize) {
            int f = leftStart;

            int mid = leftStart + currSize - 1;
            
            if (mid >= size - 1) break;

            int calcEnd = leftStart + 2 * currSize - 1;
            int l = (calcEnd < size - 1) ? calcEnd : (size - 1);

            merge(array, f, mid, l);
        }
    }
}