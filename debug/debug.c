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
		fprintf(stderr, "[%.*s]", (int)token->len, token->str);
		fprintf(stderr, " kind: %s\n", kind[token->kind]);
		token = token->next;
	}
	fprintf(stderr, "\n=====[debug_lexer]========\n");
}

void debug_parser(t_node *node)
{
	while (node)
	{
		fprintf(stderr, "cmds: ");//debug node->cmds
		while (node->cmds)
		{
			fprintf(stderr, "[%s] ", node->cmds->str);
			node->cmds = node->cmds->next;
		}
		fprintf(stderr, "\n");
		

		fprintf(stderr, "red_in: ");//debug node->red_in
		while (node->red_in)
		{
			fprintf(stderr, "[%s] ", node->red_in->str);
			node->red_in = node->red_in->next;
		}
		fprintf(stderr, "\n");
		

		fprintf(stderr, "red_out: ");//debug node->red_out
		while (node->red_out)
		{
			fprintf(stderr, "[%s] ", node->red_out->str);
			node->red_out = node->red_out->next;
		}
		fprintf(stderr, "\n");

		if (node->next)
			fprintf(stderr, "\n---PIPE---\n");
		node = node->next;
	}
}
