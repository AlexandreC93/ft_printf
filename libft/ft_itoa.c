/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:26:00 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/22 22:07:28 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(int n)
{
	int		size;

	size = 0;
	if (n == INT_MIN)
		return (11);
	if (n < 0 && n > INT_MIN)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

long int	check_tmp(long int tmp, int n)
{
	tmp = n;
	if (tmp == -2147483648)
		tmp = 2147483648;
	if (tmp < 0)
		tmp = -n;
	return (tmp);
}

char	*ft_itoa(int n)
{
	long int		tmp;
	char			*str;
	int				i;
	int				neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	i = 1;
	str = (char *)ft_calloc(ft_itoa_size(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	tmp = 0;
	tmp = check_tmp(tmp, n);
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[ft_itoa_size(n) - i++] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (neg)
		*str = '-';
	return (str);
}
