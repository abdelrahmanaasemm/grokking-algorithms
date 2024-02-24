#include <stdio.h>
#include "selectionsort.h"
int main() {
int array[6]={2,12,1,14,3,5};
    int size = sizeof (array)/sizeof (array[0]);
    selectionsort(array,size);
    printarray(array,size);
        return 0;
}

