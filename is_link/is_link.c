#define    /* Since glibc 2.20 */ _DEFAULT_SOURCE 
#define _XOPEN_SOURCE  500
#define   /* Since glibc 2.10: */ _POSIX_C_SOURCE 200112L
#define /* glibc 2.19 and earlier */ _BSD_SOURCE
#include <stdio.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    if (argc <= 1 || argc > 2)
        return 2;
    struct stat st; 
    int s = lstat(argv[1], &st);
    if (s == -1)
        return 2;
    if (S_ISLNK(st.st_mode))
    {
        printf("%s: link\n", argv[1]);
    }
    else
        printf("%s: not link\n", argv[1]);
    return 0;
}
