#include "../minishell.h"

void debug_env(char **env)
{
	fprintf(stderr, "\n=====[debug_env]========\n");
	for (size_t i = 0; env[i]; i++)
		fprintf(stderr, "%s\n", env[i]);
	fprintf(stderr, "\n=====[debug_env]=========\n]");
}
