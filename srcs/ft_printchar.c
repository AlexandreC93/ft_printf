/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:57 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/15 18:48:02 by lcadinot         ###   ########.fr       */
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
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}
