#include "./../../include/utils/memory.h"

void* allocate(size_t size, const char *file, int line) {
    void* ptr = malloc((size_t) size);
    return (ptr != NULL) ? ptr : ( print_error("Memory allocation failed", file, line), NULL );
}