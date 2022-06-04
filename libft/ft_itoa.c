/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:45:17 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/10 18:12:30 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int	len_count;

	len_count = 0;
	while (n)
	{
		n /= 10;
		len_count++;
	}
	return (len_count);
}

static char	*reverse_str(char *str, int max)
{
	int		i;
	int		j;
	int		count;
	char	tmp;

	i = 0;
	j = max;
	count = 0;
	if (str[0] == '-')
		i++;
	else
		max--;
	while (count < (j / 2))
	{
		tmp = str[i];
		str[i] = str[max];
		str[max] = tmp;
		i++;
		max--;
		count++;
	}
	return (str);
}

static void	convert_to_ascii(char *str, int n)
{
	int	i;
	int	len;

	i = 0;
	len = count_len(n);
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		i++;
	}
	while (len > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		len--;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		max;

	len = count_len(n);
	max = len;
	if (n == -0 || n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		str = (char *)malloc(sizeof(char) * (len + 2));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	convert_to_ascii(str, n);
	return (reverse_str(str, max));
}
