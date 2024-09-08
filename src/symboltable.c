#include "symboltable.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;

static size_t st_index(Symboltable *table, const char *key) {
	return (table->hash(key, strlen(key)) % table->capacity);
}


/**
 * @brief Creates a new empty symbol table.
 * 
 * Allocates memory for a symbol table and initializes its attributes,
 * including a hash function, capacity, and entries.
 * 
 * @param capacity The number of entries the symbol table can hold.
 * @param hf The hash function to be used for key hashing.
 * 
 * @return Pointer to the newly created symbol table, or NULL if allocation fails.
 */
Symboltable *st_new(uint32_t capacity, hashfunction *hf) {
	Symboltable *table = malloc(sizeof(*table));
	if (table == NULL) {
		perror("Memory allocation for symboltable failed.");
		return NULL;
	}
	table->capacity = capacity;
	table->count = 0;
	table->hash = hf;
	// note: calloc zeros out the memory
	table->entries = calloc(sizeof(Symbol *), table->capacity);

	return table;
}

/**
 * @brief Hashes a given key using a basic hashing algorithm.
 * 
 * The function computes a hash value by adding and multiplying the ASCII
 * values of the characters in the key.
 * 
 * @param key The key to hash.
 * @param length The length of the key.
 * 
 * @return The computed hash value.
 */
uint64_t hash(const char *key, size_t length) {
	uint64_t hash_value = 0;
	for (int i = 0; i < length; ++i) {
		hash_value += key[i];
		hash_value *= key[i];
	}
	return hash_value;
}

/**
 * @brief Frees all memory allocated for the symbol table.
 * 
 * This function iterates through all entries in the symbol table,
 * freeing any memory used by symbols, as well as the table itself.
 * 
 * @param table The symbol table to destroy.
 */
void st_destroy(Symboltable *table) {
	for (int i = 0; i < table->capacity; ++i) {
		free(table->entries[i]);
	}
	free(table->entries);
	free(table);
}

/**
 * @brief Inserts a symbol into the symbol table.
 * 
 * If a symbol with the same key exists, the function returns the existing symbol.
 * Otherwise, it inserts the new symbol into the appropriate index and updates the count.
 * 
 * @param table The symbol table.
 * @param entry The symbol to insert.
 * 
 * @return The inserted symbol, or the existing symbol if one with the same key exists.
 */
Symbol *st_insert(Symboltable *table, Symbol *entry) {
	assert(entry != NULL);
	size_t index = st_index(table, entry->name);

	Symbol *tmp = st_lookup(table, entry->name);
	if (tmp != NULL) {
		return entry;
	}

	entry->next = table->entries[index];
	table->entries[index] = entry;
	table->count++;
	return entry;
}


/**
 * @brief Looks up a symbol in the symbol table.
 * 
 * Searches for a symbol by key and returns it if found. If not found, returns NULL.
 * 
 * @param table The symbol table to search.
 * @param key The key of the symbol to look up.
 * 
 * @return The found symbol, or NULL if no symbol matches the key.
 */
Symbol *st_lookup(Symboltable *table, const char *key) {
	if (table == NULL || key == NULL) {
		perror("Cannot pass null argument to st_lookup.");
		return NULL;
	}
	uint32_t index = st_index(table, key);
	Symbol *tmp = table->entries[index];
	while (tmp != NULL && strcmp(tmp->name, key) != 0) {
		tmp = tmp->next;
	}
	return tmp;
}

/**
 * @brief Creates a new symbol with a label.
 * 
 * Allocates memory for a new symbol and initializes it with the given key, value, and line information.
 * 
 * @param key The name of the label.
 * @param is_data Whether the label is for data or code.
 * 
 * @return The created symbol, or NULL if memory allocation fails.
 */
Symbol *st_create_label(const char *key, bool is_data) {
	Symbol *new_entry = malloc(sizeof(Symbol));

	if (new_entry == NULL) {
		perror("Memory allocation for creation of label failed. Not enough memory.");
		return NULL;
	}

	new_entry->is_data = is_data;
	new_entry->next = NULL;
	new_entry->value = yylineno;
	new_entry->line = yylineno;
	new_entry->name = strdup(key);

	return new_entry;
}


/**
 * @brief Prints all symbols in the symbol table.
 * 
 * Iterates over the entries in the symbol table and prints each symbol's label and line number.
 * 
 * @param table The symbol table to print.
 */
void st_print(Symboltable *table) {
	printf("+-----------------+------------+-------+\n");
	printf("| Symbol Name     | Value      | Line  |\n");
	printf("+-----------------+------------+-------+\n");

	for (int i = 0; i < table->capacity; ++i) {
		Symbol *tmp = table->entries[i];
		while (tmp != NULL) {
			// Adjusting field widths for neat alignment
			printf("| %-15s | %-10d | %-5d |\n", tmp->name, tmp->value, tmp->line);
			tmp = tmp->next;
		}
	}

	printf("+-----------------+------------+-------+\n");
}
