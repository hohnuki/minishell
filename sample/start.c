#include "ease.h"

//ls -lを実行できるようにする<=現状split
//char *cmd[] = {"/bin/ls", "-l", NULL};
//execve(cmd[0], cmd, NULL);->sampleでチェック->ok

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		char *str = readline("ease> ");
		add_history(str);//"/bin/ls -l"を想定
		char **cmd = ft_split(str, ' ');
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
