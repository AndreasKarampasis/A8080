#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <stdint.h>

struct instruction {
    uint8_t opcode;
    uint8_t arg1;
    uint8_t arg2;
};


#endif // __INSTRUCTION_H__
