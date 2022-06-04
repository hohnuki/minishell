/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:54 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/10 16:04:19 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	else if (!size)
		return (NULL);
	while (s1[i] != '\0' && i < size)
	{
		j = 0;
		while (s1[i + j] != '\0' && *s2 && s1[i + j] == s2[j] && i + j < size)
			j++;
		if (j == ft_strlen(s2))
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
