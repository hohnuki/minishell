#include "../minishell.h"

//envのname=bodyとして情報を格納する関数群を作成する
//その後nameがPATHとなる部分を抽出して合致テストをしていく感じにする方が良さそう。

t_env *create_env(char **envptr)
{
	debug_env(envptr);

	t_env *env = ft_calloc(1, sizeof(t_env));
	/*
	 * 上の言語化した実装を書く。-> create_pathはpathの時に欲しくなるので
	 * 一旦create_envにしてしまって、それを作り終えてから別でcreate_path
	 * を作成する仕様に変更する予定。
	 */
	return env;
}