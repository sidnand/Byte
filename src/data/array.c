#include <stddef.h>

#include "./../../include/data/array.h"

// dynamically resize an array of any type
// @param array: the array to resize
// @param current_size: the current size of the array
// @param new_size: the new size of the array
// @param element_size: the size of each element in the array
// @return: the resized array
void* resize_array(void* array, size_t current_size, size_t new_size, size_t element_size) {
    void* new_array = realloc(array, new_size * element_size);

    if (new_array == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }

    return new_array;
}