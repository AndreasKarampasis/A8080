#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <stdint.h>



enum instr_format {
	REGISTER    = 1,
	IMMEDIATE   = 2,
	DIRECT      = 3
};

struct instruction {
	uint16_t address;
	uint8_t opcode;
	uint8_t *operand1;
	uint8_t *operand2;
	// expr*??maybe
	uint8_t instr_size;
	enum instr_format format;
};


extern struct instruction *instrs;
extern unsigned instrs_capacity;
extern unsigned int current_instrs;
extern uint16_t LC;

void emit(uint8_t op, uint8_t arg1, uint8_t arg2, enum instr_format frmt);

#endif
