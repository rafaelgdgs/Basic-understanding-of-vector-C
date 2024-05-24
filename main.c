#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct vetor vetor;
typedef struct {
  void* ptr;
  unsigned int len;
  unsigned int cap;
}vector;

vector* initialize_vector() {
  vector* vect = malloc(sizeof(vector));
  vect->ptr = NULL;
  vect->len = 0;
  vect->cap = 0;
  return vect;
}

int increase_vector_size(vector* vect, int ammount) {
  void* new_vect = malloc(sizeof(int) * (vect->cap + ammount));
  if (new_vect == NULL) {
    return -1;
  }
  memcpy(new_vect, vect->ptr, sizeof(int) * vect->len);
  free(vect->ptr);
  vect->ptr = new_vect;
  vect->cap += 1;
  return 0;
}

int push_to_vector(vector* vect, int i) {
  if (!(vect->len < vect->cap)){
    int return_value = increase_vector_size(vect, 1);
    if (return_value < 0) {return -1;}
  }
  *( ((int*)vect->ptr) + sizeof(int)*vect->len ) = i;
  vect->len += 1;
  return 0;
}

int get_element_by_index(vector* vect, int index) {
  return *( ((int*)vect->ptr) + sizeof(int)*index );
}

int main() {
  vector* vect = initialize_vector();
  push_to_vector(vect, 12);
  push_to_vector(vect, 15);
  printf("%d - %d\n", get_element_by_index(vect, 0), get_element_by_index(vect, 1));
  printf("LEN: %u CAP: %u\n", vect->len, vect->cap);

  return 0;
}
