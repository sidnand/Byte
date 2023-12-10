const int INITIAL_SIZE = 5000;
int max_tokens = INITIAL_SIZE;

// Enumeration representing token types
enum TOKEN_TYPE {
    // Arithmetic operators
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO, POWER,

    // Data types
    INT, FLOAT,
    
    // Special characters
    SEMI_COLON,

    // User-defined identifiers
    IDENTIFIER,
};

// Structure representing a token
struct TOKEN {
    enum TOKEN_TYPE type;
    char *value;
};

struct TOKEN create_token(const char *value, enum TOKEN_TYPE type);
struct TOKEN *tokenize(char **arr, int num_elements);
char **split(char *content, int *num_elements);