#include "minishell.h"

//char *cmd[] = {"/bin/ls", NULL};
//-lもできるようにする
//execve(cmd[0], cmd, NULL);

//char *cmd[] = {"/bin/ls", "-l", NULL};
//execve(cmd[0], cmd, NULL);

//"/bin/ls -l" => {"/bin/ls", "-l", NULL};//今回splitで代用

int main(int argc, char **argv, char **envp)
{
	while (1)
	{
		char *str = readline("nukishell: ");
		add_history(str);// /bin/ls


		char *cmd[] = {str, NULL};
		int pid = fork();
		if (pid == 0)
		{
			execve(cmd[0], cmd, NULL);
			return 127;
		}
			
		int status;
		wait(&status);
		if (WEXITSTATUS(status) == 127)
			printf("minishell: %s: command not found.\n", cmd[0]);
	}
	return 0;
}
