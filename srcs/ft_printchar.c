/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:57 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/25 15:38:28 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	formater_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	formater_pe(void)
{
	int		percent;

	percent = '%';
	write(1, &percent, 1);
	return (1);
}

int	formater_s(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	else if (!s)
		return (i);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
