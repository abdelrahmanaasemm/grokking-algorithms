#include "binary.h"
int main(){
    int array[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int position = binary_search(18,array,20);
    printf("position %d\n",position);
    return 0;
}