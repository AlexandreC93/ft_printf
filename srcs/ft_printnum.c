/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:48:06 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/25 19:40:32 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_uitoa_size(unsigned int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int		tmp;
	char				*str;
	int					i;

	i = 1;
	str = (char *)ft_calloc(ft_uitoa_size(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	tmp = n;
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[ft_uitoa_size(n) - i++] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}

int	formater_u(unsigned int num)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_uitoa(num);
	while (res[i])
		write(1, &res[i++], 1);
	free(res);
	return (i);
}

int	formater_d(int num)
{
	int		i;
	char	*res;

	res = ft_itoa(num);
	if (!res)
		return (0);
	i = 0;
	while (res[i])
		write(1, &res[i++], 1);
	free(res);
	return (i);
}
