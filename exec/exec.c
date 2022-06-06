#include "../minishell.h"

//char *cmd[] = {"/bin/ls", NULL};
//-lもできるようにする
//execve(cmd[0], cmd, NULL);

void exec(char *str, t_env *env)
{
	setbuf(stderr, NULL);
	
	/* debug_envlst(env); */
	char *path;

	env = env->next;//一旦、番兵ノードを回避
	while (env)
	{
		if (ft_strncmp(env->name, "PATH", 5) == 0)
			path = env->body;
		env = env->next;
	}
	char **cmd = ft_split(str, ' ');
	char **paths = ft_split(path, ':');
	debug_path(paths);

	for (int i = 0; paths[i]; i++)
	{
		path = ft_strjoin(paths[i], ft_strjoin("/", cmd[0]));
		if (access(path, F_OK) == 0)
		{
			cmd[0] = path;
			break;
		}
	}

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
