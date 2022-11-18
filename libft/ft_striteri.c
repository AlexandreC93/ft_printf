/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:59:00 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/11 16:52:41 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	while (i < j)
		(*f)(i++, s++);
}
/*
int	main(int argc, char **argv)
{
	printf("", ft_striteri(argv[1], ft_test(4, "salut")));
	return (0);
}
*/
