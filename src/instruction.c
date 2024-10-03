#include "instruction.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define EXPAND_SIZE 1024
#define CURRENT_SIZE (instrs_capacity * sizeof(Instruction))
#define NEW_SIZE (EXPAND_SIZE * sizeof(Instruction) + CURRENT_SIZE)


Instruction *instrs = (Instruction *)0;
unsigned instrs_capacity = 0;
unsigned int current_instrs = 0;

void i_expand(void) {
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

Instruction *i_emit(uint16_t addr, uint8_t op, uint8_t arg1, uint8_t arg2, InstrType type) {
  if (current_instrs == instrs_capacity) {
    i_expand();
  }
  Instruction *i = instrs + current_instrs++;
  i->address = addr;
  i->opcode = op;
  i->operand1 = arg1;
  i->operand2 = arg2;
  i->type = type;
  return i;
}

