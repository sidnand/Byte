#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> // system input/output
#include <stdbool.h> // boolean type
#include <string.h> // string manipulation
#include <libgen.h> // pattern matching
#include <stdlib.h> // memory allocation

// Structure representing a user file
struct USER_FILE {
    char *path;
    char *name;
    char *ext;
    char *content;
};

// Function prototypes
const char *read_file(char *filepath);
const char *get_extension(const char *filename);
struct USER_FILE get_file(char *filepath);


#endif // MAIN_H
