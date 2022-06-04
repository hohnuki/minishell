#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
	size_t total_len = strlen(s1) + strlen(s2);
	char *ret = malloc(sizeof(char) * (total_len + 1));
	size_t i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	size_t j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return ret;
}

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
