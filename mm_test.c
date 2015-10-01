/* A simple test harness for memory alloction. */

#include "mm_alloc.h"
#include <stdio.h>
void print(struct s_block *ths);
int main(int argc, char **argv)
{
  int *data,*data1,*data2,*data3;

    data = (int*) mm_malloc(8);
    data[0] = 1;
    data1 = (int*) mm_malloc(4);
    data1[0] = 23; 
    data2 = (int*) mm_malloc(64);
    data2[0] = 546231;
    printf("data %i , data1 %i , data2 %i\n" , *data, *data1,*data2);
    mm_free(data);
    printf("Data1 freed");
    data3 = (int*) mm_malloc(4);
    data3[0] = 32;
    printf("Data3 entered should be in data1's place value: %i\n",*data3);  
    printf("malloc sanity test successful!\n");
    print(head);
    return 0;
}

void print(struct s_block *ths){
  while(ths!= NULL){
    printf("%i \n" , ths->free);
    ths = ths->next;
  }
}
