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

void debug_path(char **paths)
{
	fprintf(stderr, "\n=====[debug_path]========\n");
	for (int i = 0; paths[i]; i++)
		fprintf(stderr, "%s\n", paths[i]);
	fprintf(stderr, "\n=====[debug_path]========\n");
}

void debug_lexer(t_token *token)
{
    fprintf(stderr, "\n=====[debug_lexer]========\n");

    const char *kind[] = {"WORD", "OPE", "END"};
    while (token)
    {
        fprintf(stderr, "str: %s\n", token->str);
        fprintf(stderr, "kind: %s\n", kind[token->kind]);
        fprintf(stderr, "len: %zu\n", token->len);
        token = token->next;
    }
    fprintf(stderr, "\n=====[debug_lexer]========\n");
}
