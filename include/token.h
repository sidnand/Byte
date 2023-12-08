const int MAX_TOKENS = 10;

// Enumeration representing token types
enum TOKEN_TYPE {
    IF, ELSE_IF, ELSE, WHILE, RETURN,
    INT, FLOAT, STR, CHAR, INT_ARR, FLOAT_ARR, STR_ARR, CHAR_ARR,
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO,
    EQUAL, NOT_EQUAL, GREATER_THAN, LESS_THAN, GREATER_THAN_EQUAL, LESS_THAN_EQUAL,
    AND, OR, NOT,
    ASSIGNMENT,
    OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE, OPEN_BRACKET, CLOSE_BRACKET,
    COMMA, SEMICOLON,
    LINE_TERMINATOR,
};

// Structure representing a token
struct TOKEN {
    enum TOKEN_TYPE type;
    char *value;
};

struct TOKEN create_token(const char *value, enum TOKEN_TYPE type);
struct TOKEN *tokenize(char **arr);
char **split(char *content);