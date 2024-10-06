#include "instruction.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define EXPAND_SIZE 1024
#define CURRENT_SIZE (instrs_capacity * sizeof(Instruction))
#define NEW_SIZE (EXPAND_SIZE * sizeof(Instruction) + CURRENT_SIZE)


Instruction *instrs = (Instruction *)0;
unsigned instrs_capacity = 0;
unsigned int current_instrs = 0;

/**
 * @brief Expands the instruction array when it reaches its capacity.
 * 
 * This function reallocates memory for the instruction array when it reaches full capacity,
 * increasing the size by a defined `EXPAND_SIZE`. The existing instructions are copied over to the
 * newly allocated memory.
 * 
 * @note The function asserts that the array is full before expanding.
 */
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

/**
 * @brief Emits a new instruction and adds it to the list of instructions.
 * 
 * This function creates a new instruction with the provided parameters and adds it
 * to the instruction array. If the instruction array is full, it calls `i_expand()` to
 * increase the capacity before adding the new instruction.
 * 
 * @param mnemonic The mnemonic of the instruction (e.g., MOV, ADD).
 * @param addr The address of the instruction.
 * @param op The opcode of the instruction.
 * @param arg1 The first operand of the instruction.
 * @param arg2 The second operand of the instruction.
 * @param type The type of the instruction (REGISTER, IMMEDIATE, or DIRECT).
 * 
 * @return A pointer to the newly emitted instruction.
 */
Instruction *i_emit(const char *mnemonic, uint16_t addr, uint8_t op, uint8_t arg1, uint8_t arg2, InstrType type) {
  if (current_instrs == instrs_capacity) {
    i_expand();
  }
  Instruction *i = instrs + current_instrs++;
  i->mnemonic = strdup(mnemonic);
  i->address = addr;
  i->opcode = op;
  i->operand1 = arg1;
  i->operand2 = arg2;
  i->type = type;
  return i;
}

/**
 * @brief Prints all emitted instructions in a formatted table.
 * 
 * This function iterates through the list of instructions (`instrs`)
 * and prints each instruction's mnemonic, address, opcode, operands, and type.
 */
void i_printInstructions() {
    if (current_instrs == 0) {
        printf("No instructions to print.\n");
        return;
    }

    // Header
    printf("+----------------+---------+--------+----------+----------+------------+\n");
    printf("| Mnemonic       | Address | Opcode | Operand1 | Operand2 | Type       |\n");
    printf("+----------------+---------+--------+----------+----------+------------+\n");

    // Loop through instructions and print each one
    for (unsigned int i = 0; i < current_instrs; ++i) {
        Instruction *instr = &instrs[i];

        // Adjusting the format for clarity
        printf("| %-14s | 0x%04X  |  0x%02X  |   0x%02X   |   0x%02X   | %-10s |\n",
               instr->mnemonic,
               instr->address,
               instr->opcode,
               instr->operand1,
               instr->operand2,
               (instr->type == REGISTER)  ? "REGISTER" :
               (instr->type == IMMEDIATE) ? "IMMEDIATE" :
                                            "DIRECT");
    }

    // Footer
    printf("+----------------+---------+--------+----------+----------+------------+\n");
}
