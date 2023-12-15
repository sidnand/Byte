#include "./../include/main.h"

int main(int argc, char *argv[]) {

    bool is_valid_args = (argc == 2);

    if (!is_valid_args) {
        print_error("Invalid arguments. Format: byte <filename>.bt", __FILE__, __LINE__);
        return 1;
    }

    char *filepath = argv[1];
    struct USER_FILE file = get_file(filepath);
    
    int num_elements_split_arr;
    char **split_arr = split(file.content, &num_elements_split_arr);

    // for (size_t i = 0; i < num_elements_split_arr; i++) {
    //     printf("%s\n", split_arr[i]);
    // }

    int num_tokens;
    struct TOKEN *tokens = tokenize(split_arr, num_elements_split_arr, &num_tokens);

    // for (size_t i = 0; i < num_tokens; i++) {
    //     struct TOKEN token = tokens[i];

    //     printf("%d: %s\n", token.type, token.value);
    // }

    // struct AST_NODE *root = parse(tokens, num_tokens);

    free(file.path);
    free(file.name);
    free(file.ext);
    free(file.content);

    return 0;
}