#include "./../include/io/reader.h"
#include "./../include/data/token.h"
#include "./../include/core/tokenizer.h"

#include "./../include/main.h"

int main(int argc, char *argv[]) {

    bool isValidArguments = (argc == 2);

    if (!isValidArguments) {
        printf("Invalid arguments.\nFormat: ./main <filename>\n");
        return 1;
    }

    char *filepath = argv[1];
    struct USER_FILE file = get_file(filepath);
    
    int num_elements_split_arr;
    char **split_arr = split(file.content, &num_elements_split_arr);

    // for (size_t i = 0; i < num_elements_split_arr; i++) {
    //     printf("%s\n", split_arr[i]);
    // }

    struct TOKEN *tokens = tokenize(split_arr, num_elements_split_arr);

    for (size_t i = 0; i < num_elements_split_arr; i++) {
        struct TOKEN token = tokens[i];

        printf("Type: %d\n", token.type);
        printf("Token: %s\n", token.value);
    }

    // FREE MEMORY

    free(file.path);
    free(file.name);
    free(file.ext);
    free(file.content);

    return 0;
}