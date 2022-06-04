#include "minishell.h"

//char *cmd[] = {"/bin/ls", NULL};
//execve(cmd[0], cmd, NULL);

int main(int argc, char **argv, char **envp)
{
	while (1)
	{
		char *str = readline("nukishell: ");
		add_history(str);// /bin/ls
		
		char *cmd[] = {str, NULL};
		execve(cmd[0], cmd, NULL);
	}
	return 0;
}
