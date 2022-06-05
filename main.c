#include "minishell.h"

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

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	while (1)
	{
		//envの情報を格納
		t_env *env = create_env(envp);

		char *str = readline("nukishell: ");
		add_history(str);// "ls | cat" -> {"ls", "|", "cat"}(use split)
		exec(str);
	}
	return 0;
}

//
//ls(親)->cat(子)
//ls -[1]->cat [0] dup2(fd[0], fd[0]);close(fd)//dup2(fd[1],fd[1]) -> pipe(fd);