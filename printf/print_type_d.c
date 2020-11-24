/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:47:54 by ylee              #+#    #+#             */
/*   Updated: 2020/11/24 09:49:18 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_d(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 'd' && arg->specifier != 'i')
		return (0);
	result = ft_itoa(va_arg(ap, int));
	result = apply_precision(arg, result);
	result = apply_width(arg, result);
	return (result);
}
