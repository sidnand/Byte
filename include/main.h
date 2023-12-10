#include "./includes.h"

#ifndef MAIN_H
#define MAIN_H

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
