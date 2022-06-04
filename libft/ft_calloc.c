/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:45:28 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/11 21:57:06 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!n || !size)
	{
		n = 1;
		size = 1;
	}
	ptr = (char *)malloc(size * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * n));
	return ((void *)ptr);
}
