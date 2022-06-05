#include "../minishell.h"

t_env	*env_lstnew(char *content)
{
	t_env	*ptr;

	ptr = malloc(sizeof(t_env));
	if (!ptr)
		return (NULL);
	ptr->name = content;//still
	ptr->next = NULL;
	return (ptr);
}

void	env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (lst)
	{
		if (*lst)
		{
			tmp = env_lstlast(*lst);
			tmp->next = new;
		}
		else
			*lst = new;
	}
}

t_env	*env_lstlast(t_env *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

size_t	env_lstsize(t_env *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}