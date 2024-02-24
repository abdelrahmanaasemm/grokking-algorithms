#include "recursion.h"
int countdown( int num){
    printf ("%d  ",num );
    if (num==1){
        return 1;
    }
    else{
        return countdown(--num);
    }
}
int factorial(int num){
    if(num==1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}