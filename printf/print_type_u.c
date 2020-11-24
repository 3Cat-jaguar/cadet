/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:56:19 by ylee              #+#    #+#             */
/*   Updated: 2020/11/24 09:49:53 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_u(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 'u')
		return (0);
	result = ft_uitoa(va_arg(ap, unsigned int));
	result = apply_precision(arg, result);
	result = apply_width(arg,result);
	return (result);
}
