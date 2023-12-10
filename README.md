# Byte

Byte is a small interpreted programming lanuage written in C. It is similar to C in terms of features, but does memory management for you and the syntax is cleaner.

## Syntax Ideas

``` c

============================== COMMENTS ==============================

// This is a comment
/* This is multiline comment */

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
**n : power of n

// Comparison
== != > < >= <=

// Logical
& : and
| : or
! : not

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

name() = {
    ...
};

name(arg1, arg2) = {
    ...
};

name() = return null;

name(arg1, arg2) = return arg1;

```