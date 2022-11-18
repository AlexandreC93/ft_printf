/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:26:08 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/11 22:52:13 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		l;

	l = ft_strlen(str);
	if (!(c <= 127 && c >= 0))
		return ((char *)str);
	while (l > 0)
	{
		if (str[l] == c)
			return ((char *)str + l);
		l--;
	}
	if (c == *str)
		return ((char *)str);
	if (c == '\0')
		return ((char *)str + l);
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	printf("%s", ft_strrchr(argv[1], 99));
	return (0);
}
*/
