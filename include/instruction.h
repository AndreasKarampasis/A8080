#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <stdint.h>

struct instruction {
    // label field
    // uint8_t opcode field
    // uint8_t DATA1
    // uint8_t DATA2
    // label address

};

extern struct instruction *instructions;
extern unsigned total;
extern unsigned int currInstr;

#endif // __INSTRUCTION_H__
