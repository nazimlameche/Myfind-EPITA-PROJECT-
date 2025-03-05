#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <err.h>
#include <dirent.h>
#include <sys/types.h>

#include "print.h"

int type_fun(char *name, char *pattern)
{
     if (fnmatch(pattern, name, 0) == 0)
     {
         return 0;
     }
     return 1;
}

int print_fun(char *name_dir)
{
    DIR *dir = opendir(name_dir);
    if (dir == NULL)
    {
        closedir(dir);
        fprintf(stderr, "error on the directory 1\n");
        return 1;
    }
    struct dirent *in_file = readdir(dir);
    for ( ;in_file; in_file = readdir(dir))
    {
        if (in_file->d_name[0] == '.')
            continue;

        char name_dir2[1024];
        snprintf(name_dir2, 1024, "%s/%s", name_dir, in_file->d_name);
        printf("%s\n", name_dir2);
        struct stat st;
        int s = stat(name_dir2,&st);
        if (s != 0)
        {
            closedir(dir);
            fprintf(stderr, "error on the directory 2\n");
            return 1;
        }
        if (S_ISDIR(st.st_mode))
        {
            int ls = print_fun(name_dir2);
            if (ls == 1)
            {
                closedir(dir);
                fprintf(stderr, "error on the directory 3");
                return 1;
            }
        }
    }
    closedir(dir);
    return 0;
}

struct node check_func(char *name)
{
    struct node res;
    res.type = ARG;
    if (strcmp(name, "-print") == 0)
        res.type = PRINT;
    else if (strcmp(name, "-name") == 0)
        res.type = NAME;
    else if (strcmp(name, "-type") == 0)
        res.type = TYPE;
    else if (strcmp(name, "-o") == 0 || strcmp(name, "-a") == 0)
        res.type = OPERATOR;
    else if (strcmp(name, "-newer") == 0)
        res.type = NEWER;
    return res;
}

struct node *parser(int len, char *argv[], int *len2)
{
    size_t len_res = 1;
    size_t cmt = 0;
    struct node *res = malloc(sizeof(struct node));
    for (int i = 1; i < len; i++)
    {
        if (cmt == len_res)
        {
            len_res++;
            res = realloc(res, len_res * sizeof(struct node));
            
        }
        res[cmt] = check_func(argv[i]);
        if (res[cmt].type != OPERATOR)
        {
            if (i + 1 == len)
            {
                free(res);
                exit(1);
            }
            else
            {
                struct node n = check_func(argv[i + 1]);
                if (n.type != ARG)
                {
                    free(res);
                    exit(1);
                }
                res[cmt].value = argv[i + 1];
                i++;
            }
        }
        else
        {
            if (res[cmt].type == ARG)
            {
                free(res);
                exit(1);
            }
            if (strcmp(argv[i], "-o") == 0 )
                res[cmt].value = "-o";
            else
                res[cmt].value = "-a";
        }
        cmt++;
    }
    *len2 = len_res;
    return res;
}



static struct stack *end_of_shunting2(struct stack *s, struct stack *lex)
{
    if (stack_size(s) != 0)
    {
        while (stack_peek(s).type != LEFT_PAR)
        {
            struct token ope = stack_peek(s);
            s = stack_pop(s);
            stack_push(lex, ope);
        }
        if (stack_peek(s).type == LEFT_PAR)
            s = stack_pop(s);
        else
            exit(2);
    }
    return s;
}



struct node *shunting(struct node *n, int len)
{
    struct stack *s_op = NULL;
    struct stack *s_oper = stack_init();
    struct node and;
    and.type = OPERATOR;
    and.value = "-a";
    size_t i = 0;
    while (i < len)
    {
        if (n[i].type == OPERATOR)
        {
            s_ope = stack_push(s_ope, n[i])
        }
        else if (n[i] != OPERATOR)
        {
            if (n[i].type != ARG && n[i] != RIGHT_PAR)
            {
                if (stack_size(s_op) != 0)
                {
                    struct node ope = stack_peek(s_op);
                    while (stack_size != 0 && ope.type != LEFT_PAR)
                    {
                        stack_push(s_oper, ope);
                        stack_pop(s_oper);
                        if (stack_size(s_op) != 0)
                        {
                            ope = stack_peek(s_ope);
                            if (ope.tye != OPERATOR)
                                s_op = stack_push(s_op, and);
                        }
                    }
                    stack_push(s_op, n[i]);
                    i++;
                }
            }
            if (n[i].type == RIGHT_PAR)
            {
                struct node n2 = stack_peek(s_op);
                while (stack_size(s_op) != 0 && n2.type != LEFT_PAR)
                {
                    s_oper = stack_push(s_oper, n2);
                    if (stack_size(s_op) != 0)
                    {
                        ope = stack_peek(s_op);
                    }
                }
            }

        }
    }
    end_of_shunting(s, s2);
    return lex;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf(".\n");
        printf(".");
    }
    int len_par = 1;
    struct node *parse = parser(argc, argv, &len_par);
    for (int i = 0; i < len_par; i++)
    {
        printf("%s\n", parse[i].value);
    }
    free(parse);
    return 0;
}
