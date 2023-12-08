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
    struct TOKEN *tokens = tokenize(split_arr);

    for (int i = 0; i < MAX_TOKENS; i++) {
        printf("%d: %s\n", tokens[i].type, tokens[i].value);
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