//
// Created by user1 on 2/15/2024.
//
#include "selectionsort.h"

int selectionsort(int *ptrarr, int size) {
    int smallindex = 0;
    for (int counter =0; counter < size; ++counter) {
        smallindex = counter;

        for (int i = counter; i < size ; ++i) {
            if (ptrarr[smallindex] > ptrarr[i]) {
                smallindex = i;
//{2,12,1,14,3,5};
            }
        }
        swap(ptrarr + counter, ptrarr + smallindex);

    }


    return smallindex;
}

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void printarray(int *ptrarr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}