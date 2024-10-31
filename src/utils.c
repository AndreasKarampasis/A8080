#include "utils.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "instruction.h"

extern Instruction *instrs;

#define EXPAND_SIZE 1024
#define CURRENT_SIZE (capacity * sizeof(unresolved_label))
#define NEW_SIZE (EXPAND_SIZE * sizeof(unresolved_label) + CURRENT_SIZE)


unresolved_label *unresolved_labels_table = NULL;
unsigned capacity = 0;
unsigned int current = 0;

/**
 * @brief Expands the unresolved labels table when it reaches capacity.
 *
 * This function reallocates the memory for the unresolved labels table by increasing its capacity.
 * If the table is not empty, it copies the current content to the newly allocated memory and frees
 * the old memory. The capacity is increased by a predefined size (EXPAND_SIZE).
 *
 * @note The capacity and current size must be equal when this function is called.
 */
void expand(void) {
  assert(capacity == current);

  unresolved_label *p = (unresolved_label *)malloc(NEW_SIZE);
  if (p == NULL) {
    perror("Error expanding unresolved labels table");
    exit(EXIT_FAILURE);
  }

  if (unresolved_labels_table) {
    memcpy(p, unresolved_labels_table, CURRENT_SIZE);
    free(unresolved_labels_table);
  }

  unresolved_labels_table = p;
  capacity += EXPAND_SIZE;
}

/**
 * @brief Inserts an unresolved label into the unresolved labels table.
 *
 * This function stores an unresolved label and its corresponding index (in the instruction list) into
 * the unresolved labels table. If the table has reached its capacity, the table is expanded.
 *
 * @param label The unresolved label to be inserted.
 * @param index The index of the instruction where the label was encountered.
 */
void unresolved_insert(const char *label, const unsigned int index) {
  if (current == capacity) {
    expand();
  }
  unresolved_labels_table[current].key = strdup(label);
  unresolved_labels_table[current].value = index;
  current++;
}

/**
 * @brief Resolves and patches all unresolved labels using the symbol table.
 *
 * This function iterates through all unresolved labels stored in the unresolved labels table,
 * checks if each label is defined in the symbol table, and patches the corresponding instructions
 * with the correct label values. If an unresolved label is not found in the symbol table, an error
 * message is displayed, and the program terminates.
 *
 * @param st A pointer to the symbol table containing defined labels.
 */
void patch_unresolved_labels(Symboltable* st) {

  for (size_t i = 0; i < current; ++i) {
    Symbol *s = st_lookup(st, unresolved_labels_table[i].key);
    if (!s) { 
      printf("\x1B[31mError:\x1B[0m Undefined label '%s'.\n", unresolved_labels_table[i].key);
      printf("  | \x1B[36mNote:\x1B[0m Label '%s' used at line %d\n",unresolved_labels_table[i].key, 0);
      exit(EXIT_FAILURE);
    }
    unsigned int index = unresolved_labels_table[i].value;
    instrs[index].operand = new_number_const_expr(s->value);

    free(unresolved_labels_table[i].key);

  }
}