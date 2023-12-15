#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

#include "./../../include/utils/error.h"

void* allocate(size_t size, const char *file, int line);

#endif