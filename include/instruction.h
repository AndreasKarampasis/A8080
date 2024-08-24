#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <stdint.h>

struct instruction {
    // label field
    // code field
    // operand field
        // arg1
        // arg2
    // label address

};

extern struct instruction *instructions;
extern unsigned total;
extern unsigned int currInstr;

#endif // __INSTRUCTION_H__
