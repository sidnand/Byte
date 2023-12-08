const int MAX_TOKENS = 10;

// Enumeration representing token types
enum TOKEN_TYPE {
    KEYWORD,     // reserved words with special meaning. e.g., if, else, while, for, true, false
    IDENTIFIER,  // names given to variables, functions, etc.
    OPERATOR,    // symbols that operate on arguments and produce results. e.g., +, -, *, /, %
    SEPARATOR,   // symbols that separate statements. e.g., ;, {, }, (, ), [, ]
    LITERAL,     // a fixed value. e.g., integer, float, string
};

// Structure representing a token
struct TOKEN {
    enum TOKEN_TYPE type;
    char *value;
};

struct TOKEN create_token(const char *value, enum TOKEN_TYPE type);
struct TOKEN *tokenize(char **arr);
char **split(char *content);