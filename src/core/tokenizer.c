#include "./../../include/data/token.h"
#include "./../../include/core/tokenizer.h"

// create a function that takes an array of strings and returns an array of tokens
// @param arr: the array of strings
// @return: an array of tokens
struct TOKEN *tokenize(char **arr, int num_elements) {
    struct TOKEN *tokens = malloc((size_t) num_elements * sizeof(struct TOKEN));

    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_elements; i++) {
        char *token = arr[i];

        if (token == NULL) {
            break;
        }

        enum TOKEN_TYPE type = get_token_type(token);

        tokens[i] = create_token(&token[0], type);
    }

    return tokens;
}

// create a function that takes a string and returns an array of tokens
// @param content: the content of the file
// @param num_elements: the number of elements in the array
// @return: an array of tokens
char **split(char *content, int *num_elements) {
    // char *split_by = " \t\n\r";
    char **tokens = malloc((strlen(content) + 1) * sizeof(char *));  // +1 for null terminator

    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (content[i] != '\0') {
        tokens[i] = malloc(2 * sizeof(char)); // 2 bytes, one for the character and one for the null terminator

        if (tokens[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        tokens[i][0] = content[i];
        tokens[i][1] = '\0';
        i++;
    }

    *num_elements = i;
    tokens[i] = NULL; // null terminator

    return tokens;
}