#include "./../../include/utils/error.h"

void print_error(const char *message, const char *file, int line) {
    fprintf(stderr, RED_TEXT "Error in %s at line %d: %s\n" RESET_TEXT, file, line, message);
    exit(EXIT_FAILURE);
}