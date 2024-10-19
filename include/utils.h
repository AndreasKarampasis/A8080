#ifndef __UTILS_H__
#define __UTILS_H__

#include "symboltable.h"

/**
 * @brief Structure to store an unresolved label and its corresponding instruction index.
 *
 * This structure holds a label (key) that is referenced but not yet defined, along with its
 * associated value (index) in the instruction list, which will be patched once the label is resolved.
 */
typedef struct _unresolved_label {
    char* key;
    unsigned int value;
}unresolved_label;

/**
 * @brief The global table to store unresolved labels.
 *
 * This table holds unresolved labels and their corresponding instruction indices. It will be used
 * for patching instructions once the labels are resolved.
 */
extern unresolved_label *unresolved_labels_table;

/**
 * @brief Inserts an unresolved label into the unresolved labels table.
 *
 * This function stores an unresolved label and its corresponding index (in the instruction list) into
 * the unresolved labels table. If the table has reached its capacity, the table is expanded.
 *
 * @param label The unresolved label to be inserted.
 * @param index The index of the instruction where the label was encountered.
 */
void unresolvedInsert(const char *label, const unsigned int index);

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
void patchUnresolvedLabels(Symboltable* st);

#endif