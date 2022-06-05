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

#endif
