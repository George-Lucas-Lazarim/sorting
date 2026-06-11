#include "quicksort.h"

int partition (int array[], int f, int l) {
    int pivot = array[l];
    int i = f - 1;

    for (int j = f; j < l; j++) {
        if (array[j] < pivot) {
            i++;
            int aux = array[j];
            array[j] = array[i];
            array[i] = aux;
        }
    }

    int aux = array[i + 1];
    array[i + 1] = array[l];
    array[l] = aux;

    return i + 1;
}

void quickSort (int array[], int f, int l) {
    if (f >= l) return;

    int pi = partition(array, f, l);

    quickSort (array, f, pi);
    quickSort (array, pi + 1, l);
}