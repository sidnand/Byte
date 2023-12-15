#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

#define RED_TEXT "\x1b[31m"
#define RESET_TEXT "\x1b[0m"

void print_error(const char *message, const char *file, int line);

#endif