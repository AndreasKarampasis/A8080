#include "instruction.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

uint16_t LC = 0; // location counter


#define EXPAND_SIZE 1024
#define CURRENT_SIZE (instrs_capacity * sizeof(Instruction))
#define NEW_SIZE (EXPAND_SIZE * sizeof(Instruction) + CURRENT_SIZE)


Instruction *instrs = (Instruction *)0;
unsigned instrs_capacity = 0;
unsigned int current_instrs = 0;

void emit(uint8_t op, uint8_t arg1, uint8_t arg2, InstrType type) {
    LC += type;
}

void quads_expand(void) {
  assert(instrs_capacity == current_instrs);

  Instruction *p = (Instruction *)malloc(NEW_SIZE);
  if (p == NULL) {
  }

  if (instrs) {
    memcpy(p, instrs, CURRENT_SIZE);
    free(instrs);
  }

  instrs = p;
  instrs_capacity += EXPAND_SIZE;
}