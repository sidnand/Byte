#ifndef READER_H
#define READER_H

#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <stdio.h>

// Structure representing a user file
struct USER_FILE {
    char *path;
    char *name;
    char *ext;
    char *content;
};

struct USER_FILE get_file(char *filepath);
const char *read_file(char *filepath);
const char *get_extension(const char *filename);

#endif