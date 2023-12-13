# Byte

Byte is a small interpreted programming lanuage written in C. It is similar to C in terms of features, but does memory management for you and the syntax is cleaner.

## File Structure (Expected)

```
- root
    |-- bins                             # Directory for executables
    |-- include                          # Header files
    |-- libs                             # Libraries
        |-- unity                          # Unit testing library
    |-- examples                         # Example programs

    |-- tests                            # Unit tests

    |-- src                              # Source code
        |-- core                           # Core files
            |-- lexer.c                     # Lexical analyzer
            |-- parser.c                    # Parser
            |-- interpreter.c               # Interpreter
        |-- data                           # Data structures
            |-- token.c                     # Token data structure for lexer
        |-- io                             # Input/Output
            |-- reader.c                    # File reader
        |-- utils                          # Utility functions

    |-- main.c                           # Main file

    |-- .gitignore                       # Gitignore file for specifying ignored files/directories
    |-- README.md                        # Project README file
    |-- Makefile                         # Makefile for building the project

```

## Syntax Ideas

```

============================== COMMENTS ==============================

// This is a comment
/* This is multiline comment */

============================== IMPORTS ==============================

import "./path/to/file.by"

============================== DATA TYPES / VARIABLES ==============================

str name = "John Doe";
char letter = 'a';
int age = 30;
float height = 1.75;
bool isMale = true;

str[] names = ["John", "Jane", "Jack"];
char[] letters = ['a', 'b', 'c'];
int[] ages = [30, 25, 20];
float[] heights = [1.75, 1.65, 1.80];
bool[] isMales = [true, false, true];
[] mixed = ["John", 30, 1.75, true, 'a'];

Person =  {
    str name;
    int age;
    float height;
    bool isMale;
    int[] scores;
};

Person john = {
    name: "John Doe",
    age: 30,
    height: 1.75,
    isMale: true,
    scores: [10, 20, 30]
};

Person[] people = [
    Person {
        name: "John Doe",
        age: 30,
        height: 1.75,
        isMale: true,
        scores: [10, 20, 30]
    },

    ...
];

============================== OPERATORS ==============================
// Arithmetic
+ : add
- : subtract
* : multiply
/ : divide
% : modulo
^n : power of n
++ : increment
-- : decrement
+= : add and assign
-= : subtract and assign

// Comparison
== != > < >= <=

// Logical
and
or
not

============================== CONTROL FLOW ==============================

if condition {

} else if condition {

} else {

};

============================== LOOPS ==============================

while condition {
    ...
};

for i = 0, i < 10, i++ {
    ...
};

============================== FUNCTIONS ==============================

str name() = {
    ...
};

float name(int arg1, char arg2) = {
    ...
};

Person name() = return john;

void name() = {
    ...
};

```