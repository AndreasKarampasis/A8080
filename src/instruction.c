#include "instruction.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(struct instruction))
#define NEW_SIZE (EXPAND_SIZE*sizeof(struct instruction)+CURR_SIZE)

struct instruction* instructions = (struct instruction*) 0;
unsigned total = 1;
unsigned int currInstr = 1;

void expand() {
	assert(total == currInstr);
	struct instruction *i = (struct instruction*) malloc(NEW_SIZE);
	if (instructions) {
		memcpy(i, instructions, CURR_SIZE);
		free(instructions);
	}
	instructions = i;
	total += EXPAND_SIZE;
}
