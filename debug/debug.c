#include "../minishell.h"

void debug_env(char **env)
{
	fprintf(stderr, "\n=====[debug_env]========\n");
	for (size_t i = 0; env[i]; i++)
		fprintf(stderr, "%s\n", env[i]);
	fprintf(stderr, "\n=====[debug_env]=========\n");
}

void debug_envlst(t_env *env)
{
	fprintf(stderr, "\n===[debug_envlst]===\n");
	while (env)
	{
		fprintf(stderr, "name:%s\n", env->name);
		fprintf(stderr, "body:%s\n", env->body);
		env = env->next;
	}
	fprintf(stderr, "\n===[debug_envlst]===\n");
}
