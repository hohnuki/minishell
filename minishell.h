#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"


/*purpose:change envp to (name=body)*/
typedef struct s_env {
	char *name;
	char *body;
	struct s_env *next;
} t_env;

/*purpose:get kind of token*/
typedef enum e_kind {
	WORD,//e.g.)"ls", "cat", "-l"...
	OPE,//e.g.)"|", "<<", "<", ">", ">>"
	END,//end of file(EOF is conflict)
} t_kind;

/*purpose:get traits of token*/
typedef struct s_token {
	t_kind kind;//kind of token
	size_t len;//len of token
	char *str;//分析(lex)対象文字
	
	struct s_token *next;
} t_token;

/*purpose: get info of parser*/
typedef struct s_node {
	
	struct s_node *cmds;//cmds/red_in/red_out...を全て同じデータ構造でもつ
	struct s_node *red_in;
	struct s_node *red_out;
	
	char *cmd;
	char *str;
	int is_builtin;
	char *pathname;
	struct s_node *next;
} t_node;

t_env *create_env(char **env);
void debug_env(char **env);
t_env	*env_lstnew(char *name, char *body);
void	env_lstadd_front(t_env **lst, t_env *new);
t_env	*env_lstlast(t_env *lst);
void	env_lstadd_back(t_env **lst, t_env *new);
size_t	env_lstsize(t_env *lst);
size_t	strchr_ret_sizet(const char *s, int c);
char *ft_strndup(const char *str, size_t n);

/* lexer.c */
t_token *lexer(char *str);

/* parser.c */
t_node *parser(t_token *token);

/* debug.c */
void debug_envlst(t_env *env);
void debug_path(char **paths);
void debug_lexer(t_token *token);
void debug_parser(t_node *node);

/* exec.c */
void exec_start(char *str, t_env *env, char **envp);

#endif
