/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:55:30 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/25 19:05:45 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		puthexa_base(long int num, char type);
int		formater_c(char c);
int		formater_s(char *s);
int		formater_d(int num);
int		formater_i(int num);
int		formater_x(int num, char type);
int		formater_p(unsigned long long num, int i);
int		ft_uitoa_size(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		check_num(long int num, int j, char type);
int		formater_u(unsigned int num);
int		formater_pe(void);

#endif
