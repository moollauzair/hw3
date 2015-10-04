#include "mm_alloc.h"
#include <unistd.h>
#include <stdlib.h>

/* Your final implementation should comment out this macro. */
#define MM_USE_STUBS

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
  struct s_block *temp;
  temp = head;
  if(head == NULL){
    return;
  }
  
  while(temp->next != NULL){
    if(temp->ptr == ptr){
      temp->free = 1;
      return;
    }
      temp = temp->next;

  }  
}
