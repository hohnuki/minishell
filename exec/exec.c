#include "../minishell.h"

//char *cmd[] = {"/bin/ls", NULL};
//-lもできるようにする
//execve(cmd[0], cmd, NULL);

void exec(char *str)
{
	char **cmd = ft_split(str, ' ');
	if (ft_strncmp(cmd[0], "/bin/", 5) != 0)
		cmd[0] = ft_strjoin("/bin/", cmd[0]);
	int pid = fork();
	if (pid == 0)
	{
		execve(cmd[0], cmd, NULL);
		exit (127);
	}
	int status;
	wait(&status);
	if (WEXITSTATUS(status) == 127)
		printf("minishell: %s: command not found.\n", cmd[0]);
}
