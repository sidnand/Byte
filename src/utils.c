#include "../include/utils.h"

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

// returns the extension of a file
// @param filename: the name of the file
// @return: the extension of the file
const char *get_extension(const char *filename) {
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
const char *read_file(char *filepath) {
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *content = malloc(file_size + 1);

    if (content == NULL) {
        fclose(file);
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    size_t bytes_read = fread(content, 1, file_size, file);
    content[bytes_read] = '\0'; // null terminate

    if (bytes_read != (size_t) file_size) {
        fclose(file);
        fprintf(stderr, "Error reading file\n");
        exit(EXIT_FAILURE);
    }

    return content;
}