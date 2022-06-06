#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	while (1)
	{
		//input
		char *str = readline("nukishell: ");
		add_history(str);// "ls | cat" -> {"ls", "|", "cat"}(use split)

		//lexer
		t_token *token = lexer(str);
		debug_lexer(token);

		//parser && expansion
		
		//envの情報を格納
		t_env *env = create_env(envp);
		/* debug_envlst(env); */
		
		//exec
		exec_start(str, env, envp);
	}
	return 0;
}

