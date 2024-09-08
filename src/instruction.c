#include "instruction.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>


#define EXPAND_SIZE 1024
#define CURRENT_SIZE (instrs_capacity * sizeof(struct instruction ))
#define NEW_SIZE (EXPAND_SIZE * sizeof(struct instruction ) + CURRENT_SIZE)

uint16_t LC = 0;

struct instruction *instrs = (struct instruction *)0;
unsigned instrs_capacity = 0;
unsigned int current_instrs = 0;

void emit(uint8_t op, uint8_t arg1, uint8_t arg2, enum instr_format frmt) {
    
}

void quads_expand(void) {
  assert(instrs_capacity == current_instrs);

  struct instruction *p = (struct instruction *)malloc(NEW_SIZE);
  if (p == NULL) {
  }

  if (instrs) {
    memcpy(p, instrs, CURRENT_SIZE);
    free(instrs);
  }

  instrs = p;
  instrs_capacity += EXPAND_SIZE;
}