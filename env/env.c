#include "../minishell.h"

//envのname=bodyとして情報を格納する関数群を作成する
//その後nameがPATHとなる部分を抽出して合致テストをしていく感じにする方が良さそう。

char *ft_strndup(const char *str, size_t n)
{
	char *ret = malloc(sizeof(char) * n);
	size_t i = 0;
	while (str[i] && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return ret;
}


t_env *create_env(char **envptr)
{
	debug_env(envptr);

	t_env *env = ft_calloc(1, sizeof(t_env));

	for (size_t i = 0; envptr[i]; i++)
	{
		char *equal = ft_strchr(envptr[i], '=');
		char *name = ft_strndup(envptr[i], strchr_ret_sizet(envptr[i], '='));
		char *body = ft_strdup(equal + 1);
		env_lstadd_back(&env, env_lstnew(name, body));
	}

	debug_envlst(env);
	/*
	 * 上の言語化した実装を書く。-> create_pathはpathの時に欲しくなるので
	 * 一旦create_envにしてしまって、それを作り終えてから別でcreate_path
	 * を作成する仕様に変更する予定。
	 */
	return env;
}
