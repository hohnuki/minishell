/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:51:33 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/10 18:12:21 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	check_negative(int n_i, int ope_i)
{
	int	i;

	i = 0;
	if (ope_i > 1 || n_i > 1)
		i = 0;
	else if (n_i % 2 == 1)
		i = -1;
	else
		i = 1;
	return (i);
}

static int	check_long(long ans, char c, int n_i)
{
	if ((ans * 10) + (c - '0') - LONG_MAX >= 0 && n_i % 2 != 1)
		return (-1);
	else if ((ans * 10) + (c - '0') + LONG_MIN >= 0 && n_i % 2 == 1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			n_i;
	int			ope_i;
	long long	ans;

	i = 0;
	n_i = 0;
	ope_i = 0;
	ans = 0;
	while (check_isspace(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n_i++;
		ope_i++;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (check_long(ans, str[i], n_i) != 1)
			return (check_long(ans, str[i], n_i));
		ans = (ans * 10) + ((str[i++] - '0'));
	}
	return (ans * check_negative(n_i, ope_i));
}
