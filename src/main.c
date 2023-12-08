#include <stdio.h> // system input/output
#include <stdbool.h> // boolean type
#include <string.h> // string manipulation
#include <libgen.h> // pattern matching
#include <stdlib.h> // memory allocation

// FUNCTION PROTOTYPES
const char *readFile(char *filepath);
const char *getExtension(const char *filename);
struct USER_FILE getFile(char *filepath);

// STRUCTS
struct USER_FILE {
    char *path;
    char *name;
    char *ext;
    char *content;
};

enum TOKEN_TYPE {
    KEYWORD,        // reserved words with special meaning. e.g. if, else, while, for, true, false
    IDENTIFIER,     // names given to variables, functions, etc.
    OPERATOR,       // symbols that operate on arguments and produce results. e.g. +, -, *, /, %
    SEPARATOR,      // symbols that separate statements. e.g. ;, {, }, (, ), [, ]
    LITERAL,        // a fixed value. e.g. integer, float, string
};

struct TOKEN {
    char *value;
    struct TOKEN_TYPE type;
};

int main(int argc, char *argv[]) {

    // bool isValidArguments = (argc == 2);

    // if (!isValidArguments) {
    //     printf("Invalid arguments.\nFormat: ./main <filename>\n");
    //     return 1;
    // }

    char *filepath = argv[1];
    struct USER_FILE file = getFile(filepath);

    printf("Path: %s\n", file.path);
    printf("Name: %s\n", file.name);
    printf("Extension: %s\n", file.ext);
    printf("Content: %s\n", file.content);

    free(file.path);
    free(file.name);
    free(file.ext);
    free(file.content);

    return 0;
}

// returns a USER_FILE struct
// @param filepath: the path to the file
// @return: a USER_FILE struct
struct USER_FILE getFile(char *filepath) {
    struct USER_FILE file;

    const char *absolute_path = realpath(filepath, NULL);
    const char *filename = basename(filepath);
    const char *extension = getExtension(filename);
    const char *content = readFile(filepath);

    // allocate memory and copy strings
    file.path = strdup(absolute_path);
    file.name = strdup(filename);
    file.ext = strdup(extension);
    file.content = strdup(content);

    return file;
}

// returns the extension of a file
// @param filename: the name of the file
// @return: the extension of the file
const char *getExtension(const char *filename) {
    const char *extension = strrchr(filename, '.');
    if (extension != NULL) {
        extension++; // Move past the '.'
    } else {
        extension = "No extension";
    }

    return extension;
}

// reads a file and returns
// @param filepath: the path to the file
// @return: the content of the file
const char *readFile(char *filepath) {
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *content = malloc(file_size + 1);

    if (content == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(content, 1, file_size, file);
    content[bytes_read] = '\0'; // null terminate

    if (bytes_read != file_size) {
        perror("Error reading file");
        fclose(file);
        return NULL;
    }

    return content;
}