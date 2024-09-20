#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <stdint.h>

extern uint16_t LC; // location counter

typedef enum _instr_format {
	REGISTER    = 1,
	IMMEDIATE   = 2,
	DIRECT      = 3
} InstrType;

typedef struct _instr {
	uint16_t address;	// 0x0000-0xFFFF valid address
	uint8_t opcode;
	uint8_t *operand1;	// TODO: maybe expr
	uint8_t *operand2;	// TODO: maybe expr
	InstrType type;
} Instruction;

extern Instruction *instrs;
extern unsigned instrs_capacity;
extern unsigned int current_instrs;

void emit(uint8_t op, uint8_t arg1, uint8_t arg2, InstrType type);

#endif
