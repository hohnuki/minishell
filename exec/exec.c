#include "../minishell.h"

void exec(char *str, t_env *env, char **envp)
{
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
	/* debug_path(paths); */
	
	for (int i = 0; paths[i]; i++)
	{
		path = ft_strjoin(paths[i], ft_strjoin("/", cmd[0]));
		if (access(path, F_OK) == 0)
		{
			cmd[0] = path;
			break;
		}
	}
	execve(cmd[0], cmd, envp);
}

void go_pipe(char **cmds, t_env *env, char **envp, size_t begin)
{
	if (cmds[begin] == NULL)
		return ;
	if (cmds[begin + 1] == NULL)
		exec(cmds[begin], env, envp);
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		exec(cmds[begin], env, envp);
	}
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	go_pipe(cmds, env, envp, begin + 1);
}

void exec_start(char *str, t_env *env, char **envp)
{
	/* debug_envlst(env); */

	char **cmds = ft_split(str, '|');
	size_t begin = 0;
	
	int pid = fork();
	if (pid == 0)
	{
		go_pipe(cmds, env, envp, begin);
		exit(127);
	}
	int status;
 	wait(&status);
	if (WEXITSTATUS(status) == 127)
		printf("minishell: %s: command not found.\n", cmds[0]);
}
