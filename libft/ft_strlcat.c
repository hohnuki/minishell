/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:08:12 by hohnuki           #+#    #+#             */
/*   Updated: 2022/04/26 23:01:23 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	measure_ret_val(size_t ds, size_t dest_len, size_t src_len)
{
	if (dest_len >= ds)
		return (src_len + ds);
	else
		return (dest_len + src_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	return_value;
	size_t	dest_len;
	size_t	src_len;
	size_t	first_dest_len;

	i = 0;
	return_value = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	first_dest_len = dest_len;
	if (!destsize)
		return (src_len + destsize);
	return_value = measure_ret_val(destsize, dest_len, src_len);
	while (first_dest_len + i < destsize - 1 && src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (return_value);
}
