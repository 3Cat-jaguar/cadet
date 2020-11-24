/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:00:39 by ylee              #+#    #+#             */
/*   Updated: 2020/11/24 09:50:09 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_x(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 'x')
		return (0);
	result = ft_itoa_base16(va_arg(ap, unsigned int));
	result = apply_precision(arg, result);
	result = apply_width(arg,result);
	return (result);
}
