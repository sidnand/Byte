#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "./../../include/utils/error.h"
#include "./../../include/utils/memory.h"
#include "./../../include/data/token.h"

struct TOKEN *tokenize(char **arr, int num_elements, int *num_tokens);
char **split(char *content, int *num_elements);

#endif