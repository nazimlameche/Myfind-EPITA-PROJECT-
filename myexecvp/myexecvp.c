#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void my_exec(char *argv[])
{
	pid_t pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		execvp(argv[1], argv + 1);
		exit(1);
	}
	else
	{
		int status = 0;
		waitpid(pid, &status, 0);
		if (status != 0)
			exit(1);
		exit(status);
	}
}
int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		exit(1);
	}
	my_exec(argv);
	return 0;
}
