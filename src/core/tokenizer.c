#include "./../../include/data/token.h"
#include "./../../include/core/tokenizer.h"

// create a function that takes an array of strings and returns an array of tokens
// @param arr: the array of strings
// @return: an array of tokens
struct TOKEN *tokenize(char **arr, int num_elements, int *num_tokens) {
    struct TOKEN *tokens = malloc((size_t) num_elements * sizeof(struct TOKEN));

    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int char_i = 0;
    int token_i = 0;
    char *buffer = malloc(num_elements * sizeof(char));

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    buffer[0] = '\0';
    
    while (char_i < num_elements) {
        char *token = arr[char_i];

        if (token == NULL) {
            break;
        }

        bool buffer_empty = strlen(buffer) == 0;
        bool is_numeric = isdigit(token[0]) || is_period(token[0]);
        bool is_alpha = isalpha(token[0]);

        if (is_numeric) {
            strcat(buffer, token);
            char_i++;
            
            if (arr[char_i] != NULL) {
                continue;
            }
        }
        
        if (is_alpha) {
            strcat(buffer, token);
            char_i++;
            
            if (arr[char_i] != NULL) {
                continue;
            }
        }

        if (!buffer_empty) {
            enum TOKEN_TYPE type = get_token_type(buffer);
            tokens[token_i] = create_token(buffer, type);
            printf("End Buffer: %s\n\n", buffer);

            buffer[0] = '\0';
            token_i++;

            if (is_numeric || is_alpha) {
                continue;
            }
        }

        enum TOKEN_TYPE type = get_token_type(token);
        tokens[token_i] = create_token(&token[0], type);

        char_i++;
        token_i++;
    }

    free(buffer);
    *num_tokens = token_i;
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