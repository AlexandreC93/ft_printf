/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:16 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/22 16:22:53 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	formater_p(unsigned long long num)
{

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
		//	printf("i9 >> %d\n", i);
		}
		else
		{
			ft_putchar_fd(num - 10 + 97, 1);
		//	printf("ia >> %d\n", i);
		}
	}
	//printf("end >> %d\n", i);
	return (12);
}
