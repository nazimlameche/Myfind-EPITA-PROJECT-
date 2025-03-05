#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

struct stack *stack_push(struct stack *s, struct node tok)
{
    struct stack *res = malloc(sizeof(struct stack));
    res->data = tok;
    res->next = s;
    return res;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;
    struct stack *popped = s->next;
    free(s);
    return popped;
}

struct node stack_peek(struct stack *s)
{
    return s->data;
}

int stack_size(struct stack *s)
{
    int res = 0;
    while (s != NULL)
    {
        res++;
        s = s->next;
    }
    return res;
}
