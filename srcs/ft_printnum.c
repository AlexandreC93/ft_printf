/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:06 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/20 18:29:51 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	puthexa_base(long int num, char type)
{
	char	res[100];
	char	sign;
	char	*base;
	int		i;
	int		j;

	i = 0;
	j = 0;
	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	sign = '-';
	if (num < 0)
	{
		write(1, &sign, 1);
		num = -num;
	}
	while (num)
	{
		res[i++] = num % 16;
		num = num / 16;
		j++;
	}
	while (--i >= 0)
		write(1, &base[(int)res[i]], 1);
	return (j);
}

int	formater_u(unsigned int num)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_itoa(num);
	while (res[i])
		write(1, &res[i++], 1);
	return (1);
}

int	formater_x(long int num, char type)
{
	num = puthexa_base(num, type);
	return (1);
}

int	formater_d(int num)
{
	int		i;
	char	*res;

	res = ft_calloc(ft_strlen(ft_itoa((long int)num)) + 1, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	res = ft_itoa((long int)num);
	while (res[i])
		write(1, &res[i++], 1);
	return (i);
}
