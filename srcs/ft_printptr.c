/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:16 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/24 16:39:48 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	formater_p(unsigned long long num)
{
	int		i;
	//unsigned long long tmp;

	i = 0;
	//printf("\n%llu\n", num);
	while (num >= 16)
	{
		//printf("loop> %llu\n", num);
		num  = num % 16;
		//printf("loop> %llu\n", num);
		num  = num / 16;
		printf("loop> %llu\n", num);
	//	printf("tmp> %llu\n", tmp);
	
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
		i++;
	}
	printf("end >> %d\n", i);
	return (i);
}
