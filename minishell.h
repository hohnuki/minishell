#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"


typedef struct s_path {
	char *name;
	char *body;
	struct s_path *next;
} t_path;

t_path *create_path(char **env);
void debug_env(char **env);

#endif
