#ifndef STACK_H
#define STACK_H

#include "print.h"

struct stack
{
    struct node data;
    struct stack *next;
};

struct stack *stack_init(void);
struct stack *stack_push(struct stack *s, struct node e);
struct stack *stack_pop(struct stack *s);
struct node stack_peek(struct stack *s);
int stack_size(struct stack *s);

#endif /* !STACK_H */
