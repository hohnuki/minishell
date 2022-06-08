#include "../minishell.h"

void debug_env(char **env)
{
	fprintf(stderr, RED"\n=====[debug_env]========\n"STOP);
	for (size_t i = 0; env[i]; i++)
		fprintf(stderr, "%s\n", env[i]);
	fprintf(stderr, RED"\n=====[debug_env]=========\n"STOP);
}

void debug_envlst(t_env *env)
{
	fprintf(stderr, GREEN"\n===[debug_envlst]===\n"STOP);
	while (env)
	{
		fprintf(stderr, "name:%s\n", env->name);
		fprintf(stderr, "body:%s\n", env->body);
		env = env->next;
	}
	fprintf(stderr, GREEN"\n===[debug_envlst]===\n"STOP);
}

void debug_path(char **paths)
{
	fprintf(stderr, CYAN"\n=====[debug_path]========\n"STOP);
	for (int i = 0; paths[i]; i++)
		fprintf(stderr, "%s\n", paths[i]);
	fprintf(stderr, CYAN"\n=====[debug_path]========\n"STOP);
}

void debug_lexer(t_token *token)
{
	fprintf(stderr, BLUE"\n=====[debug_lexer]========\n"STOP);
	const char *kind[] = {"WORD", "OPE", "END"};
	while (token)
	{
		fprintf(stderr, "[%.*s]", (int)token->len, token->str);
		fprintf(stderr, " kind: %s\n", kind[token->kind]);
		token = token->next;
	}
	fprintf(stderr, BLUE"\n=====[debug_lexer]========\n"STOP);
}

void debug_parser(t_node *node)
{
	fprintf(stderr, MAGENTA"\n=======[debug_parser]=======\n"STOP);
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
			fprintf(stderr, "---PIPE---\n");
		node = node->next;
	}
	fprintf(stderr, MAGENTA"\n=======[debug_parser]=======\n"STOP);
}
