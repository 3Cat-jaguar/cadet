/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_x_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:03:33 by ylee              #+#    #+#             */
/*   Updated: 2020/11/24 09:50:20 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_x_upper(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 'X')
		return (0);
	arg->specifier = 'x';
	result = print_type_x(ap, arg);
	result = ft_toupper_str(result);
	arg->specifier = 'X';
	result = apply_precision(arg, result);
	result = apply_width(arg,result);
	return (result);
}
