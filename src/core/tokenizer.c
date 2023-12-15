#include "./../../include/utils/error.h"
#include "./../../include/utils/memory.h"
#include "./../../include/data/token.h"
#include "./../../include/core/tokenizer.h"

// create a function that takes an array of strings and returns an array of tokens
// @param arr: the array of strings
// @return: an array of tokens
struct TOKEN *tokenize(char **arr, int num_elements, int *num_tokens) {
    size_t token_size = num_elements * sizeof(struct TOKEN);
    struct TOKEN *tokens = allocate(token_size, __FILE__, __LINE__);

    int char_i = 0;
    int token_i = 0;
    size_t buffer_size = num_elements * sizeof(char);
    char *buffer = allocate(buffer_size, __FILE__, __LINE__);
    
    while (char_i < num_elements) {
        char *token = arr[char_i];
        if (token == NULL) { break; }

        bool buffer_empty = strlen(buffer) == 0;
        bool is_numeric = isdigit(token[0]) || is_period(token[0]);
        bool is_alpha = isalpha(token[0]);
        bool is_grouping = is_numeric || is_alpha;

        if (is_grouping) {
            strcat(buffer, token);
            char_i++;
            
            if (arr[char_i] != NULL) {
                continue;
            }
        } 
        
        if (!buffer_empty) {
            enum TOKEN_TYPE type = get_token_type(buffer);
            tokens[token_i] = create_token(buffer, type);

            token_i++;
            
            buffer[0] = '\0';
            if (is_grouping) { continue; }
        }

        enum TOKEN_TYPE type = get_token_type(token);
        tokens[token_i] = create_token(&token[0], type);

        token_i++;
        char_i++;
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
    size_t tokens_size = (strlen(content) + 1) * sizeof(char *); // +1 for null terminator
    char **tokens =  allocate(tokens_size, __FILE__, __LINE__);

    int i = 0;
    for (; content[i] != '\0'; i++) {
        size_t token_size = 2 * sizeof(char); // 2 bytes, one for the character and one for the null terminator
        tokens[i] = allocate(token_size, __FILE__, __LINE__);

        tokens[i][0] = content[i];
        tokens[i][1] = '\0';
    }

    *num_elements = i;
    tokens[i] = NULL; // null terminator

    return tokens;
}