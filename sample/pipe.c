#include "ease.h"

char *cmd1[] = {"/bin/ls", "-l", NULL};
char *cmd2[] = {"/bin/ls", NULL};
char *cmd3[] = {"/bin/cat", NULL};

char **cmds[] = {cmd1, cmd2, cmd3, NULL};

void	pipe_exec(char ***cmd, int i)
{
	if (cmd[i] == NULL)
		exit(127);
	if (cmd[i + 1] == NULL)
	{
		execve(cmds[i][0], cmds[i], NULL);
		exit(127);
	}

	int fd[2];
	pipe(fd);

	int pid = fork();

	//child
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve(cmds[i][0], cmds[i], NULL);
		exit(127);
	}
	//parent
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		pipe_exec(cmds, i + 1);
	}
}

int main(void)
{
	int pid = fork();
	if (pid == 0)
		pipe_exec(cmds, 0);
	int sts;

	wait(&sts);
}