#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <stdint.h>


typedef enum _instr_format {
	REGISTER    = 1,
	IMMEDIATE   = 2,
	DIRECT      = 3
} InstrType;

typedef struct _instr {
	char *mnemonic;
	uint16_t address;	// 0x0000-0xFFFF valid address
	uint8_t opcode;
	uint8_t operand1;	// TODO: maybe expr
	uint8_t operand2;	// TODO: maybe expr
	InstrType type;
} Instruction;

extern Instruction *instrs;
extern unsigned instrs_capacity;
extern unsigned int current_instrs;

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
Instruction *i_emit(const char *mnemonic, uint16_t addr, uint8_t op, uint8_t arg1, uint8_t arg2, InstrType type);

/**
 * @brief Prints all emitted instructions in a formatted table.
 * 
 * This function iterates through the list of instructions (`instrs`)
 * and prints each instruction's mnemonic, address, opcode, operands, and type.
 */
void i_printInstructions();

#endif
