#include "binary.h"

int binary_search(int num, int*ptr_array,int size) {
  int low = 0;
  int high= size-1;
    int mid;
  while(low < high){
      mid =(low+high)/2;
      if(ptr_array[mid]==num){
          return mid;
      }
      else if (num>mid){
          low = mid + 1;
      }
      else
          high = mid - 1;
  }
    return 0;
}