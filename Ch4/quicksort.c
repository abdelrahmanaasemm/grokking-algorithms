//
// Created by user1 on 2/16/2024.
//
#include "quicksort.h"
void swap(int *ptr1,int *ptr2){
    int temp = *ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int partition(int *ptrarr, int start, int end) {
    int pivot = ptrarr[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; ++j) {
        if (ptrarr[j] < pivot) {
            i++;
            swap(ptrarr+i,ptrarr+j);

        }
    }
    i++;
    swap(ptrarr+i,ptrarr+end);
    return i;
}

void quicksort(int *ptrarr, int start, int end) {
    if (end <= start) return;
    int pivot = partition(ptrarr, start, end);
    quicksort(ptrarr, start, pivot - 1);
    quicksort(ptrarr, pivot + 1, end);
}
void printarray(int* ptrarr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}