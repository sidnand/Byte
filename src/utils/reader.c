#include "./../../include/utils/reader.h"

// returns a USER_FILE struct
// @param filepath: the path to the file
// @return: a USER_FILE struct
struct USER_FILE get_file(char *filepath) {
    struct USER_FILE file;

    const char *absolute_path = realpath(filepath, NULL);
    const char *filename = basename(filepath);
    const char *extension = get_extension(filename);
    const char *content = read_file(filepath);

    // allocate memory and copy strings
    file.path = strdup(absolute_path);
    file.name = strdup(filename);
    file.ext = strdup(extension);
    file.content = strdup(content);

    return file;
}

// get the extension of a file
// @param filename: the name of the file
// @return: the extension of the file
const char *get_extension(const char *filename) {
    const char *extension = strrchr(filename, '.');
    if (extension != NULL) {
        extension++; // Move past the '.'
    } else {
        extension = "";
    }

    return extension;
}

// get contents of a file
// @param filepath: the path to the file
// @return: the content of the file
const char *read_file(char *filepath) {
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        print_error("Error opening file", __FILE__, __LINE__);
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    size_t content_size = file_size + 1;

    char *content = allocate(content_size, __FILE__, __LINE__);

    size_t bytes_read = fread(content, 1, file_size, file);
    content[bytes_read] = '\0'; // null terminate

    if (bytes_read != file_size) {
        fclose(file);
        print_error("Error reading file", __FILE__, __LINE__);
    }

    return content;
}