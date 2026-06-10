#include "bubblesort.h"

void bubbleSort (int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        bool changed = false;

        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                int aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;

                changed = true;
            }
        }

        if (!changed) break; 
    }
}