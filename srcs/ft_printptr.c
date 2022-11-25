/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:16 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/25 16:52:41 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	check_num(long int num, int j, char type)
{
	j = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		j++;
	}
	if (num < 0 && type != 'p')
	{
		ft_putchar_fd('-', 1);
		num = -num;
		j++;
	}
	return (j);
}

int	formater_p(unsigned long long num)
{
	int		i;

	i = 0;
	while (num >= 16)
	{
		num = num % 16;
		num = num / 16;
		if (num <= 9)
		{
			ft_putchar_fd(num + 48, 1);
			i++;
		}
		else
		{
			ft_putchar_fd(num - 10 + 97, 1);
			i++;
		}
		i++;
	}
	return (i);
}

int	puthexa_base(unsigned long int num, char type)
{
	char	res[20];
	char	*base;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (type == 'p' && num == 0)
		return (write(1, "(nil)", 5));
	if (type == 'p')
		j += write(1, "0x", 2);
	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	j += check_num(num, j, type);
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

int	formater_x(long int num, char type)
{
	num = puthexa_base(num, type);
	return (num);
}
