#include "./../../include/utils/error.h"
#include "./../../include/utils/memory.h"

void* allocate(size_t size, const char *file, int line) {
    void* ptr = malloc(size);
    print_error("Memory allocation failed", file, line);
    return (ptr != NULL) ? ptr : ( print_error("Memory allocation failed", file, line), NULL );
}