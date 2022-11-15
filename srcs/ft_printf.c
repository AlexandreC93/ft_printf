/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:36:19 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/15 19:36:57 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

/*----------------printnum----------------------------*/

int ft_printhexa(const char *str, int num)
{
    return (1);       
}

int ft_printinteger(const char *str, int num)
{
    return (1);
}

int ft_printdecimal(const char *str, int num)
{
    return (1);
}

int ft_printprcnt(const char *str, int num)
{
    return (1);
}
/*----------------------printchar---------------------------*/

char	ft_printchar(const char *str, const char c)
{
	//printf("writed >>>");
	write(1, &c, 1);
	return (c);
	
}

char	*ft_printstr(const char *str, const char *value)
{
	
	return ((char *)str);
}

/*-----------------------------------------------------------*/

char	ft_format(const char *str, void *value)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (str[i])
	{
		if (c == '%')
		{
			i++;
			if (str[i]== 'd')
				ft_printdecimal(str, (int)value);
			else if (str[i]== 'c')
				ft_printchar(str, (const char)value);
			else if (str[i]== 'i')
				ft_printinteger(str, (int)value);
			else if (str[i]== 'x')
				ft_printhexa(str, (int)value);
			else if (str[i]== 'X')
				ft_printhexa(str, (int)value);
			else if (str[i]== '%')
				ft_printprcnt(str, (int)value);
			else if (str[i]== 's')
				ft_printstr(str, (const char *)value);
		}
		i++;
	}
}

int	ft_printf(const char *str, void *value)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	ft_format(str, value);
	return (c);
}
int	main(int argc, char **argv)
{
	int		deci = 10;
	int		hexa;
	int		maj_hexa;
	char	character = 'b';
	char	str[4];
	char	*ptr;
	int		prcnt;
	int		i = 3;

	ft_printf("%c", (void *)character);
	//printf("deci == %d", deci);
	//printf("hexa == %x", hexa);
	//printf("maj_hexa == %X", maj_hexa);
	//printf("character == %c", character);
	//printf("str == %s", str);
	//printf("ptr == %p", ptr);
	//printf("prcnt == %%", prcnt);
	//printf("integer == %i", integer);
	return (0);
}
