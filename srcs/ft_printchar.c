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

char	ft_printchar(char *str, const char c)
{
	write(1, &c, 1);
	return (c);
}


