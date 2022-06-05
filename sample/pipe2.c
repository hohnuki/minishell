//
// Created by 大貫　弘貴 on 2022/06/05.
//
#include "../minishell.h"

void pipe_exec(char **cmds, size_t i)
{
	//cmds >> {"ls -l", "cat", "NULL"};
	if (cmds[i] == NULL)
		exit(127);

	int fd[2];
	pipe(fd);
	int pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve(cmds[0], cmds, NULL);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		pipe_exec(cmds, i + 1);
	}
}

int	main(void)
{
	char *str = "/bin/ls | /bin/cat";
	char **cmds = ft_split(str, '|');

	int pid = fork();
	if (pid == 0)
		pipe_exec(cmds, 0);

	setbuf(stdout, NULL);

	int sts;
	wait(&sts);
	if (WEXITSTATUS(sts) == 127)
		printf("command not fount:%s\n", str);
}