#include "utils.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define EXPAND_SIZE 1024
#define CURRENT_SIZE (capacity * sizeof(int))
#define NEW_SIZE (EXPAND_SIZE * sizeof(int) + CURRENT_SIZE)

int *unresolved_jumps_index_array = NULL;
unsigned capacity = 0;
unsigned int current = 0;

void expand(void) {
  assert(capacity == current);

  int *p = (int *)malloc(NEW_SIZE);
  if (p == NULL) {
  }

  if (unresolved_jumps_index_array) {
    memcpy(p, unresolved_jumps_index_array, CURRENT_SIZE);
    free(unresolved_jumps_index_array);
  }

  unresolved_jumps_index_array = p;
  capacity += EXPAND_SIZE;
}

void unresolvedInsert(int index) {
  if (current == capacity) {
    expand();
  }
  unresolved_jumps_index_array[current] = index;
  current++;
}