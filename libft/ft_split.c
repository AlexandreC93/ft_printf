/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:20:25 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/13 17:12:21 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char to_find, char c)
{
	if (to_find == c)
		return (1);
	return (0);
}

static char	**free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_wordcount(const char *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (ft_is_space(str[i], c)))
			i++;
		if (str[i] && !(ft_is_space(str[i], c)))
		{
			count++;
			while (str[i] && !(ft_is_space(str[i], c)))
				i++;
		}
	}
	return (count);
}

static int	ft_wordlen(const char *str, char c)
{
	int		len;

	len = 0;
	while (ft_is_space(*str, c))
		str++;
	while (*str && !(ft_is_space(*str, c)))
	{
		str++;
		len++;
	}
	return (len);
}

char	**ft_split(const char *str, char charset)
{
	int		i;
	int		j;
	int		words;
	char	**arr;

	i = 0;
	words = ft_wordcount(str, charset);
	arr = ft_calloc(words + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < words)
	{
		arr[i] = ft_calloc(ft_wordlen(str, charset) + 1, sizeof(char));
		if (!arr[i])
			return (free_tab(arr));
		j = 0;
		while (ft_is_space(*str, charset))
			str++;
		while (*str && (!ft_is_space(*str, charset)))
			arr[i][j++] = *str++;
		i++;
	}
	return (arr);
}
/*
int	main(int argc, char **argv)
{
	ft_split(argv[1], 'a');
	return (0);
}
*/
