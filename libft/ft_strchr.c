/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:20:47 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/11 22:51:36 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (!(c <= 127 && c >= 0))
		return ((char *)str);
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	printf("%s", ft_strchr(argv[1], 'l'));
	return (0);
}
*/
