#include <stdio.h>
#include <unistd.h>

char *cmd[] = {"/bin/ls", NULL};

int main(int argc, char **argv, char **envp)
{
	execve(cmd[0], cmd, NULL);
	return 0;
}
