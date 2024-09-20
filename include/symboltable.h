#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

typedef uint64_t(hashfunction)(const char *, size_t);

uint64_t hash(const char *key, size_t length);

typedef struct _symbol {
	const char* name;
	uint16_t value;
	bool is_data;
	int line;
	struct _symbol *next;  // hashtable entry chain
} Symbol;

typedef struct _symboltable {
	size_t count;     // number of key/value pairs currently
	size_t capacity;  // allocated size of the array
	hashfunction *hash;
	Symbol **entries;
} Symboltable;

/*
 * Returns a new empty symboltable
 */
Symboltable *st_new(uint32_t capacity, hashfunction *hf);

/*
 * Free all memory that symboltable uses
 */
void st_destroy(Symboltable *table);

void st_print(Symboltable *table);

/*
 * Stores the information in entry in the table at hashfunction(name). It
 * may expand the symboltable to accommodate the record for name. It returns the
 * newly added entry.
 */
Symbol *st_insert(Symboltable *table, Symbol *entry);

/**
 * @brief Search for the record in the table.
 *
 * @param table
 * @param key
 *
 * @return Returns the record stored in the table at h(name) if one exists.
 * Otherwise, it returns null indicating that name was not found.
 */
Symbol *st_lookup(Symboltable *table, const char *key);

Symbol *st_new_symbol(const char *key, bool is_data);

#endif
