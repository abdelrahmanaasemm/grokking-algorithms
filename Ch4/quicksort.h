//
// Created by user1 on 2/16/2024.
//

#ifndef CH4_QUICKSORT_H
#define CH4_QUICKSORT_H
#include "stdlib.h"
#include "stdio.h"
void quicksort(int* ptrarr,int start ,int end);
int partition(int* ptrarr,int start ,int end);
void swap(int *ptr1,int *ptr2);
void printarray(int* ptrarr, int size) ;
#endif //CH4_QUICKSORT_H
