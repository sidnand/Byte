#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void *resize_array(void *array, size_t current_size, size_t new_size, size_t element_size);

#endif