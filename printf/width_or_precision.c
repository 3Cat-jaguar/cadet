/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_or_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:42:04 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 13:59:15 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		width_or_precision(va_list ap, t_arg *arg, char *str)
{
	int		i;

	i = 0;
	if (str[i] >= '1' && str[i] <= '9')
	{
		if (arg->dot == 0)
			arg->width = ft_atoi(str);
		else if (arg->dot == 1)
			arg->precision = ft_atoi(str);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else if (str[i] == '*')
	{
		if (arg->dot == 0)
			arg->width = va_arg(ap, int);
		else if (arg->dot == 1)
			arg->precision = va_arg(ap, int);
		i++;
	}
	return (i);
}
