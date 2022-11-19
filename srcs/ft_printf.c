/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:36:19 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/19 19:31:49 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <limits.h>

/*-------------------------STRUCT------------------------*/

typedef struct Data Data;
struct	Data
{
	int		arg_num;
	char	type;
	int		neg;
};

int	puthexa_base(long int num, Data data)
{
	char	res[100];
	char	sign;
	char	*base;
	int		i;
	int		j;

	i = 0;
	j = 0;
	base = "0123456789ABCDEF";
	if (data.type == 'x')
		base = "0123456789abcdef";
	sign = '-';
	if (num < 0)
	{
		write(1, &sign, 1);
		num = -num;
	}
	while (num)
	{
		res[i] = num % 16;
		num = num / 16;
		i++;
		j++;	
	}
	while (--i >= 0)
		write(1, &base[res[i]], 1);
	return (j);
}

/*----------------printnum----------------------------*/

int formater_x(Data data, va_list ap)
{
	long int		num;

	num = va_arg(ap, long int);
	num = puthexa_base(num, data);
		
	return (1);       
}

int	formater_d(Data data, va_list ap)
{
	int		i;
	int		num;
	char	*res;

	i = 0;
	num = va_arg(ap, int);
	res = ft_itoa(num);
	while (res[i])
		write(1,&res[i++], 1);
	return (i);
}

int formater_p(Data data, va_list ap)
{
	void	*p;
	void	*p1;
	p1 = va_arg(ap, void *);
	printf("ptr > %p", p);
	write(1, *p, 15);
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
	int		percent;

	percent = '%';
	write(1, &percent, 1);
	return (1);
}

int	formater_u(Data data, va_list ap)
{
	unsigned int	num;
	char	*res;
	int		i;

	i = 0;
	num = va_arg(ap, unsigned int);
	res = ft_itoa(num);
	while (res[i])
		write(1, &res[i++], 1);
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
		//	printf("ty > %c\n", data.type);
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
	int		deci = 198;
	int		hexa;
	int		maj_hexa;
	char	character = 'b';
	char	str[4];
	void	*ptr;
	int		prcnt;

	char s2[50] = "ca va";
	char s1[50] = "salut";
	
	printf("pr >> %p\n", &ptr);
	ft_printf("ft >> %p\n", &ptr);
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
