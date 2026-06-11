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
        auxArray[k] = array[i];
        i++;
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