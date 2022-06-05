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

		//lex && per
		
		//envの情報を格納
		t_env *env = create_env(envp);
		/* debug_envlst(env); */
		
		//exec
		exec(str, env);
	}
	return 0;
}

//
//ls(親)->cat(子)
//ls -[1]->cat [0] dup2(fd[0], fd[0]);close(fd)//dup2(fd[1],fd[1]) -> pipe(fd);
