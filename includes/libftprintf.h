/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:41:47 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/18 14:09:01 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

int		ft_printf(const char *);

typedef struct Data Data;
struct Data
{
	char	type;
	int		neg;
};

#endif
