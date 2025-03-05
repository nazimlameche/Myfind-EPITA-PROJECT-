#include <assert.h>
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "memory.h"
#include "parser.h"

int eval_expr(struct my_expr *expr)
{
    if (expr->type == EXPR_ADDITION)
    {
        return eval_expr(expr->data.children.left)
            + eval_expr(expr->data.children.right);
    }
    else if (expr->type == EXPR_SUBTRACTION)
    {
        return eval_expr(expr->data.children.left)
            - eval_expr(expr->data.children.right);
    }
    else if (expr->type == EXPR_MULTIPLICATION)
    {
        return eval_expr(expr->data.children.left)
            * eval_expr(expr->data.children.right);
    }
    else if (expr->type == EXPR_NEGATION)
    {
        return -eval_expr(expr->data.children.left);
    }
    else if (expr->type == EXPR_DIVISION)
    {
        if (eval_expr(expr->data.children.right) == 0)
            return 1;
        return eval_expr(expr->data.children.left)
            / eval_expr(expr->data.children.right);
    }
    return expr->data.value;
}

// int main(int argc, char *argv[])
//{
//  struct my_expr *expr = parse_expr(argv + 1, argc - 1);
// printf("%i\n", eval_expr(expr));
//  free_expr(expr);
//  return 0;
//}
