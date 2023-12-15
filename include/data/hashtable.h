#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"

#define TABLE_SIZE 100

struct KeyValue {
    char *key;
    enum TOKEN_TYPE value;
    struct KeyValue *next;  // Pointer to the next key-value pair in case of collisions
};

struct KeyValue *hashTable[TABLE_SIZE];

unsigned int hash(char *key);
void insert(char *key, enum TOKEN_TYPE value);
enum TOKEN_TYPE get_value(char *key);
void free_hash_table();