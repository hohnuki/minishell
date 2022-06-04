#include "minishell.h"

void debug_env(char **env)
{
	for (int i = 0; env[i]; i++)
		fprintf(stderr, "%s\n", env[i]);
}

//envのname=bodyとして情報を格納する関数群を作成する
//その後nameがPATHとなる部分を抽出して合致テストをしていく感じにする方が良さそう。

t_path *create_path(char **env)
{
	debug_env(env);

	t_path *path = ft_calloc(1, sizeof(t_path));
	
	return path;
}
