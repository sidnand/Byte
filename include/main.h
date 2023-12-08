#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> // system input/output
#include <stdbool.h> // boolean type
#include <string.h> // string manipulation
#include <libgen.h> // pattern matching
#include <stdlib.h> // memory allocation
#include <ctype.h> // character type

// Structure representing a user file
struct USER_FILE {
    char *path;
    char *name;
    char *ext;
    char *content;
};

// Function prototypes
struct USER_FILE get_file(char *filepath);


#endif // MAIN_H
