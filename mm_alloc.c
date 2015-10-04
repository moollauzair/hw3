#include "mm_alloc.h"
#include <unistd.h>
#include <stdlib.h>

/* Your final implementation should comment out this macro. */
#define MM_USE_STUBS

s_block_ptr fusion(s_block_ptr b){
    b->size += b->next->size;
    b->next = b->next->next;
    return(b);
  }

void* mm_malloc(size_t size)
{
  struct s_block *temp;
  temp = head;
  if(head==NULL){
    head = sbrk(BLOCK_SIZE);
    head->ptr = sbrk(size);
    head->size = size;
    head->free = 0;
    return head->ptr;
  }
  else{
    while(temp->next != NULL){ 
      if(temp->free == 1 && temp->size == size){
	temp->next->prev = temp;
	//temp->ptr = sbrk(size);
	//temp->size = size;
	temp->free = 0;
	return temp->ptr;
      }
      else if(temp->free == 1 && temp->size > size){
	//splits block
	struct s_block *new;
	temp->next->prev = temp;
	new = temp->data + size;
	new->size = temp->size - size;
	temp->size = size;
	new->next = temp->next;
	temp->next = new;
	temp->free = 0;
	new->free = 1;
	return temp->ptr;
      }
      else{
	temp->next->prev = temp;
	temp = temp->next;
      }  
    }
    temp->next = sbrk(BLOCK_SIZE);
    temp->next->prev = temp;
    temp = temp->next;
    temp->ptr = sbrk(size);
    temp->size = size;
    temp->free = 0;
    return temp->ptr;
  }
  return NULL;
}

void* mm_realloc(void* ptr, size_t size)
{

  return NULL;
}

void mm_free(void* ptr)
{
  struct s_block *temp, *temp2;
  temp = head;
  if(head == NULL){
    return;
  }

  if(temp->ptr == ptr && temp->next == NULL){
   temp->free = 1;
   return;
  }
  
  while(temp->next != NULL){
    temp2 = temp->next;
    temp2->prev = temp;
    if(temp->ptr == ptr && temp2->free != 1){
      temp->free = 1;
      return;
    }
    else if(temp->ptr == ptr && temp2->free == 1  && temp->free != 1){
      temp->size += temp2->size;
      temp->next = temp2->next;
      temp->free = 1;
      return;
    }
    else if(temp->ptr == ptr && temp->prev->free == 1 && temp2->free != 1){ 
      temp->free = 1;
      temp = temp->prev;
      temp->size += temp->next->size;
      temp->next = temp->next->next;
      return;
    }
    else if(temp->ptr == ptr && temp->prev->free == 1 && temp2->free == 1){ 
      temp->size += temp2->size;
      temp->next = temp2->next;
      temp->prev->size += temp->size;
      temp->prev->next = temp->next;
      temp->free = 1;
      return;
    }
    else{
      temp->next->prev = temp;
      temp = temp->next;
    }
  }
 if(temp->ptr == ptr){
   temp->free = 1;
   return;
 }
}
