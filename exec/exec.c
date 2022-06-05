#include "../minishell.h"

//char *cmd[] = {"/bin/ls", NULL};
//-lもできるようにする
//execve(cmd[0], cmd, NULL);

void debug_onepath(char *path)
{
	fprintf(stderr, "path body:%s\n", path);
}

void exec(char *str, t_env *env)
{
	setbuf(stderr, NULL);
	
	/* debug_envlst(env); */
	char *path;
	
	while (env)
	{
		if (ft_strncmp(env->name, "PATH", 5) == 0)
			path = env->body;
		env = env->next;
	}
	debug_onepath(path);
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
