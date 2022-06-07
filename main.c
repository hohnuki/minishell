#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	//envの情報を格納
	t_env *env = create_env(envp);
	/* debug_envlst(env); */

	while (1)
	{
		//input
		char *str = readline("nukishell: ");
		add_history(str);// "ls | cat" -> {"ls", "|", "cat"}(use split)

		//lexer
		t_token *token = lexer(str);
		debug_lexer(token);

		//parser
		t_node *node = parser(token);
		debug_parser(node);
		
		//expansion
		
		//exec
		fprintf(stderr, "\n!!!!!exec!!!!!!\n");
		exec_start(str, env, envp);
	}
	return 0;
}
