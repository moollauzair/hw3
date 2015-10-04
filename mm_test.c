/* A simple test harness for memory alloction. */

#include "mm_alloc.h"
#include <stdio.h>
void print(struct s_block *ths);
int main(int argc, char **argv)
{
/*
  int *data,*data1,*data2,*data3;

    data = (int*) mm_malloc(8);
    data[0] = 1;

    printf("Data = 11\n");

    data1 = (int*) mm_malloc(4);
    data1[0] = 23;

    printf("Data1 = 23\n");
    printf("\n Printing List now:\n");
    print(head);
    mm_free(data);
    printf("Data freed\n");

    data2 = (int*) mm_malloc(4);
    data2[0] = 546231;

    printf("Data2 = 546231\n");
    printf("\n Printing List now:\n");
    print(head);

    data3 = (int*) mm_malloc(2);
    data3[0] = 32;

    printf("Data3 = 32\n");
    printf("\n Printing List now\n");  
    print(head);
    
    printf("malloc sanity test successful!\n");

    return 0;
*/

///*
  int *data;

    data = (int*) mm_malloc(4);
    data[0] = 1;
    mm_free(data);
    printf("malloc sanity test successful!\n");
    return 0;

//*/
}

void print(struct s_block *ths){
  while(ths!= NULL){
    printf("Free: %i \n" , ths->free);
    printf("Size: %i \n" , ths->size);
    ths = ths->next;
  }
}
