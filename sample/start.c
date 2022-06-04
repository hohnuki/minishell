#include "ease.h"


//ls -lを実行できるようにする<=現状split
//char *cmd[] = {"/bin/ls", "-l", NULL};
//execve(cmd[0], cmd, NULL);->sampleでチェック
int main(int argc, char **argv, char **envp)
{
	while (1)
	{
		char *str = readline("yeah!> ");
		add_history(str);
		str = ft_strjoin("/bin/", str);
		char *cmd[] = {str, NULL};

		int pid = fork();
		if (pid == 0)
		{
			execve(cmd[0], cmd, NULL);
			exit(127);
		}
		else
		{
			int sts;
			wait(&sts);
			if (WEXITSTATUS(sts) == 127)
				printf("command not found:%s\n", str);
		}
	}
	return 0;
}
