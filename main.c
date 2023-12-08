#include "./include/main.h"

#include "./src/utils.c"

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

struct TOKEN create_token(const char *value, enum TOKEN_TYPE type) {
    struct TOKEN token;
    token.value = strdup(value);
    token.type = type;
    return token;
}

// create a function that takes a string and returns an array of tokens
// @param content: the content of the file
// @return: an array of tokens
char **split(char *content) {
    char *split_by = " \t\n\r(){}";
    char **tokens = malloc(MAX_TOKENS);

    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(content, split_by);

    int i = 0;
    while (token != NULL) {
        if (i % MAX_TOKENS == 0) {
            tokens = resize_array(tokens, i, i + MAX_TOKENS, sizeof(char *));
        }

        tokens[i++] = token;
        token = strtok(NULL, split_by);
    }

    return tokens;
}