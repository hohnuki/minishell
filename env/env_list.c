#include "../minishell.h"

t_env	*env_lstnew(char *name, char *body)
{
	t_env	*ptr;

	ptr = malloc(sizeof(t_env));
	if (!ptr)
		return (NULL);
	ptr->name = name;
	ptr->body = body;
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

size_t	strchr_ret_sizet(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}