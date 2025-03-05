#ifndef AST_H
#define AST_H

#include <stddef.h>

#include "func.h"

struct function
{
    char *name;
    int (*fun)(char *);
};

struct function funcs[1] =
{
    { .name = "print", .fun = print_fun}
};

enum operator_type
{
    AND,
    OR,
    NOT,
    LEFT_PAR,
    RIGHT_PAR
};

enum node_type
{
    PRINT,
    NAME,
    TEST,
    TYPE,
    NEWER,
    DELETE,
    EXEC,
    OPERATOR,
    LEFT_PAR,
    RIGHT_PAR,
    ARG
};

struct token
{
    enum node_type type;
    char *value;
};
struct node
{
    enum node_type type;
    struct node *left;
    struct node *right;
    char* value;
};

#endif /* !PRINT_H */
