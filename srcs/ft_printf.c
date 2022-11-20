/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:36:19 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/20 15:00:28 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	formater(va_list ap, char type)
{
	int	str_len;

	str_len = 0;
	if (type == 'd' || type == 'i')
		str_len += formater_d(va_arg(ap, int));
	else if (type == 'u')
		str_len += formater_u(va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		str_len += formater_x(va_arg(ap, int), type);
	else if (type == 'c')
		str_len += formater_c(va_arg(ap, int));
	else if (type == 's')
		str_len += formater_s(va_arg(ap, char *));
	else if (type == 'p')
		str_len += formater_p(va_arg(ap, unsigned long long));
	else if (type == '%')
		str_len += formater_pe();
	return (str_len);
}

int	parser(const char *format, va_list ap)
{
	char	type;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			type = format[i + 1];
			j += formater(ap, type);
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

	va_start(ap, str);
	parser(str, ap);
	va_end(ap);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	int		deci = 198;
// 	int		hexa;
// 	int		maj_hexa;
// 	char	character = 'b';
// 	char	str[4];
// 	void	*ptr;
// 	int		prcnt;
// 	char s2[50] = "ca va";
// 	char s1[50] = "salut";
// 	printf("pr >> %c\n", 2);
// 	ft_printf("ft >> %c\n", 2);
// 	//printf("deci == %d", deci);
// 	//printf("hexa == %x", hexa);
// 	//printf("majhexa == %X", maj_hexa);
// 	//printf("character == %c", character);
// 	//printf("str == %s", str);
// 	//printf("ptr == %p", ptr);
// 	//printf("prcnt == %%", prcnt);
// 	//printf("integer == %i", integer);
// 	return (0);
// }
