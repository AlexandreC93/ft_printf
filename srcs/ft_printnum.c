/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:06 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/22 20:59:51 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_num(long int num, int j)
{
	j = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		j++;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	return (j);
}

int	puthexa_base(long int num, char type)
{
	char	res[20];
	char	*base;
	int		i;
	int		j;

	i = 0;
	j = 0;
	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	j = check_num(num, j);
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
	res = ft_itoa((unsigned int)num);
	while (res[i])
		write(1, &res[i++], 1);
	free(res);
	return (i);
}

int	formater_x(long int num, char type)
{
	num = puthexa_base(num, type);
	return (num);
}

int	formater_d(int num)
{
	int		i;
	char	*res;

	//printf("check >> %d\n", num);
	res = ft_itoa(num);
	if (!res)
		return (0);
	i = 0;
	while (res[i])
		write(1, &res[i++], 1);
	free(res);
	return (i);
}
