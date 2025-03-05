#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc <= 1 || argc > 2)
		return 2;
	struct stat stat_v;
	int stat_m = stat(argv[1], &stat_v);
	if (stat_m == -1)
		return 2;
	int statchmod = stat_v.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
	printf("%o\n", statchmod);
	return 0;
}
