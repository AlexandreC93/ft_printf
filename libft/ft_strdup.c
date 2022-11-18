/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:21:14 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/09 16:06:11 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		lenght;
	int		i;

	i = 0;
	lenght = ft_strlen(str);
	dest = malloc(sizeof(char) * lenght + 1);
	if (!dest)
		return (((void *) 0));
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(int argc, char **argv)
{
	printf("%s\n", ft_strdup(argv[1]));
	return (0);
}
*/
