#include "minishell.h"

void debug_env(char **env)
{
	for (int i = 0; env[i]; i++)
		fprintf(stderr, "%s\n", env[i]);
}

t_path *create_path(char **env)
{
	debug_env(env);
	return NULL;
}
