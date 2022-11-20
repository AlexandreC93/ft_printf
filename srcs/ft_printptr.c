/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:16 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/20 15:54:47 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	formater_p(unsigned long long num)
{
	printf("ptr > %lld", num);
	if (num >= 16)
	{
		formater_p(num / 16);
		formater_p(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd(num + 48, 1);
		}
		else
		{
			ft_putchar_fd(num - 10 + 97, 1);
		}
	}
	return (1);
}
