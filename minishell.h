#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"


typedef struct s_env {
	char *name;
	char *body;
	struct s_env *next;
} t_env;

t_env *create_env(char **env);
void debug_env(char **env);
t_env	*env_lstnew(char *content);
void	env_lstadd_front(t_env **lst, t_env *new);
t_env	*env_lstlast(t_env *lst);
void	env_lstadd_back(t_env **lst, t_env *new);
size_t	env_lstsize(t_env *lst);

#endif
