#include <err.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if (argc <= 2 || argc > 4)
	{
		exit(2);
	}
	struct passwd *pass = getpwnam(argv[2]);
	if (pass == NULL)
	{
		printf("user %s does not exist\n", argv[2]);
		exit(0);
	}
	struct stat st;
	int check = stat(argv[1], &st);
	if ( check == -1 )
	{
		exit(2);
	}
	if (st.st_uid == pass->pw_uid)
	{
		printf("%s does belong to user %s\n", argv[1], argv[2]);
		exit(0);
	}
	printf("%s does not belong to user %s\n", argv[1], argv[2]);
	exit(0);
}
