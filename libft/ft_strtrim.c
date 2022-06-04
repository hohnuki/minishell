/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:18 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/10 18:12:51 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start_number(const char *str, const char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (!ft_strchr(set, str[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	find_end_number(const char *str, const char *set)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	while (str_len >= 0)
	{
		if (!ft_strrchr(set, str[str_len]))
			break ;
		if (str_len == 0)
			return (0);
		str_len--;
	}
	return (str_len + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = find_start_number(s1, set);
	end = find_end_number(s1, set);
	i = 0;
	if (end == 0 && start == ft_strlen(s1))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
