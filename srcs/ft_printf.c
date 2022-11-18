/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:36:19 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/18 14:56:48 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

/*-------------------------STRUCT------------------------*/

typedef struct Data Data;
struct	Data
{
	char	type;
	int		neg;
};

/*----------------printnum----------------------------*/

int formater_x(Data data, va_list ap)
{
    return (1);       
}

int	formater_d(Data data, va_list ap)
{
	return (1);
}

int formater_p(Data data, va_list ap)
{
    return (1);
}
/*----------------------printchar---------------------------*/

int	formater_c(Data data, va_list ap)
{
	
	//printf("writed >>>");
	return (1);
}

int	formater_pe(Data data, va_list ap)
{
	return (1);
}

int	formater_u(Data data, va_list ap)
{
	return (1);
}

int	formater_s(Data data, va_list ap)
{
	int	value;

	value = 0;
	return (value);
}

/*-----------------------------------------------------------*/

int	formater(struct Data data, va_list ap)
{
	int	str_len;

	str_len = 0;
	
	if (data.type == 'd' || data.type == 'i')
		str_len += formater_d(data, ap);
	else if (data.type == 'u')
		str_len += formater_u(data, ap);
	else if (data.type == 'x' || data.type == 'X')
		str_len += formater_x(data, ap);
	else if (data.type == 'c')
		str_len += formater_c(data, ap);
	else if (data.type == 's')
		str_len += formater_s(data, ap);
	else if (data.type == 'p')
		str_len += formater_p(data, ap);
	else if (data.type == '%')
		str_len += formater_pe(data, ap);
	return (str_len);
}

void	parser(const char *format, va_list ap, Data data)
{
	int		i;
	char	ret;

	i = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			data.type = format[i + 1];
			i = formater(data, ap);
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		nb_params;
	char	c;
	va_list		ap;
	void	*cur_params;
	Data	data;

	parser(str, ap, data);
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

	ft_printf("%c %c", character, character);
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
