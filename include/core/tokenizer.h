#ifndef TOKENIZER_H
#define TOKENIZER_H

struct TOKEN *tokenize(char **arr, int num_elements, int *num_tokens);
char **split(char *content, int *num_elements);

#endif