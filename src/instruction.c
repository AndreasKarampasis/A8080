#include "instruction.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define EXPAND_SIZE 1024
#define CURRENT_SIZE (instrs_capacity * sizeof(Instruction))
#define NEW_SIZE (EXPAND_SIZE * sizeof(Instruction) + CURRENT_SIZE)


Instruction *instrs = NULL;
unsigned int instrs_capacity = 0;
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
    perror("Error expanding unresolved labels table");
    exit(EXIT_FAILURE);
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
 * @param arg The first operand of the instruction.
 * @param type The type of the instruction (REGISTER, IMMEDIATE, or DIRECT).
 * 
 * @return A pointer to the newly emitted instruction.
 */
Instruction *i_emit(const char *mnemonic, uint16_t addr, uint8_t op, Expr* arg, InstrType type) {
  if (current_instrs == instrs_capacity) {
    i_expand();
  }
  Instruction *i = instrs + current_instrs++;
  i->mnemonic = strdup(mnemonic);
  i->address = addr;
  i->opcode = op;
  i->operand = arg;
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
    printf("+----------------+---------+--------+----------+------------+\n");
    printf("| Mnemonic       | Address | Opcode | Operand  | Type       |\n");
    printf("+----------------+---------+--------+----------+------------+\n");

    // Loop through instructions and print each one
    for (unsigned int i = 0; i < current_instrs; ++i) {
        Instruction *instr = &instrs[i];

        // Determine the operand value based on its type
        char operand_str[16];  // Buffer to hold operand as a string
        if (instr->operand) {
            if (instr->operand->type == NUM_CONST) {
                snprintf(operand_str, sizeof(operand_str), "0x%04X", instr->operand->number_const);
            } else if (instr->operand->type == STRING_CONST && instr->operand->str_const) {
                snprintf(operand_str, sizeof(operand_str), "\"%s\"", instr->operand->str_const);
            }
        } else {
            snprintf(operand_str, sizeof(operand_str), "N/A");
        }

        // Print each instruction in formatted form
        printf("| %-14s | 0x%04X  |  0x%02X  | %-8s | %-10s |\n",
               instr->mnemonic,
               instr->address,
               instr->opcode,
               operand_str,
               (instr->type == REGISTER)  ? "REGISTER" :
               (instr->type == IMMEDIATE) ? "IMMEDIATE" :
                                            "DIRECT");
    }

    // Footer
    printf("+----------------+---------+--------+----------+------------+\n");
}
