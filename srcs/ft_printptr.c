/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:16 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/22 22:45:43 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	formater_p(unsigned long long num)
{
	int		i;

	i = 0;
	while (num >= 16)
	{
		num = num % 16;
		num = num / 16;
		i++;
	}
	if (num <= 9)
	{
		ft_putchar_fd(num + 48, 1);
		//	printf("i9 >> %d\n", i);
		i++;
	}
	else
	{
		ft_putchar_fd(num - 10 + 97, 1);
		//	printf("ia >> %d\n", i);
		i++;
	}
	printf("end >> %d\n", i);
	return (i);
}
