/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:36:19 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/18 17:06:03 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/*-------------------------STRUCT------------------------*/

typedef struct Data Data;
struct	Data
{
	int		arg_num;
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
	char	c;
	int		i;

	i = 0;
	c = va_arg(ap, int);
	write(1, &c, 1);
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
	char	*s;
	int		i;

	i = 0;
	s = va_arg(ap, char *);
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

/*-----------------------------------------------------------*/

/*
int	ft_count_args()
{
	
}
*/
int	formater(struct Data data, va_list ap, const char *format)
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
	{
		str_len += formater_c(data, ap);
	}
	else if (data.type == 's')
	{
		str_len += formater_s(data, ap);
	}	
	else if (data.type == 'p')
		str_len += formater_p(data, ap);
	else if (data.type == '%')
		str_len += formater_pe(data, ap);
	return (str_len);
}

int	parser(const char *format, va_list ap, Data data)
{
	int		i;
	int		j;
	char	ret;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			data.type = format[i + 1];
			printf("ty > %c\n", data.type);
			j += formater(data, ap, format);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	Data	data;

	va_start(ap, str);
	parser(str, ap, data);
	va_end(ap);
	return (1);
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

	char s2[50] = "ca va";
	char s1[50] = "salut";

	ft_printf("%s || %s", s1, s2);
	//printf("deci == %d", deci);
	//printf("hexa == %x", hexa);
	//printf("majhexa == %X", maj_hexa);
	//printf("character == %c", character);
	//printf("str == %s", str);
	//printf("ptr == %p", ptr);
	//printf("prcnt == %%", prcnt);
	//printf("integer == %i", integer);
	return (0);
}
