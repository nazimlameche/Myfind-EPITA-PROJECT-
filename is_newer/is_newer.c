#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc <= 1 || argc > 3)
    {
        return 2;
    }
    struct stat st1;
    int s1 = stat(argv[1], &st1);
    if (s1 == -1)
        return 2;
    struct stat st2;
    int s2 = stat(argv[2], &st2);
    if (s2 == -1)
        return 2;
    if (st1.st_mtime > st2.st_mtime)
    {
        printf("%s is not newer than %s\n", argv[1], argv[2]);
    }
    else
    {
        printf("%s is newer than %s\n", argv[1], argv[2]);
    }
    return 0;
}
