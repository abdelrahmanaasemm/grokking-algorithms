#include <stdio.h>
#include"quicksort.h"
int main() {
    int array[15]={2,5,6,2,64,43,43,4,645,78,868,45,78,7,2};
    quicksort(array,0,14);
    printarray(array,15);
    return 0;
}
