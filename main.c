#include "./include/main.h"

#include "./src/utils.c"
#include "./src/token.c"

int main(int argc, char *argv[]) {

    bool isValidArguments = (argc == 2);

    if (!isValidArguments) {
        printf("Invalid arguments.\nFormat: ./main <filename>\n");
        return 1;
    }

    char *filepath = argv[1];
    struct USER_FILE file = get_file(filepath);
    
    char **split_arr = split(file.content);
    for (int i = 0; split_arr[i] != NULL; i++) {
        printf("%s\n", split_arr[i]);
    }


    // FREE MEMORY
    free(file.path);
    free(file.name);
    free(file.ext);
    free(file.content);

    return 0;
}

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