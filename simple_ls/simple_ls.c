#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 1 && argc != 2)
        return 1;
    DIR *dir;
    if (argc == 2)
        dir = opendir(argv[1]);
    else
        dir = opendir(".");
    if (dir  == NULL)
    {
        closedir(dir);
        fprintf(stderr, "%s: No such file directory", argv[1]);
        return 1;
    }
    struct dirent *in_file = readdir(dir);
    for ( ;in_file ;in_file = readdir(dir))
    {
        if (in_file->d_name[0] == '.')
            continue;
        printf("%s\n", in_file->d_name);
    }
    closedir(dir);
    //if (cl == -1)
    //    return 1;
    return 0;
}
