/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str_by_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:43:04 by ylee              #+#    #+#             */
/*   Updated: 2020/11/30 15:40:42 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*modify_str_by_arg(va_list ap, t_arg *arg)
{
	char	*result;
	char	spcf;

	result = NULL;
	spcf = (char)(arg->specifier);
	if (spcf == 'd' || spcf == 'i')
		result = print_type_d(ap, arg);
	else if (spcf == 'c')
		result = print_type_c(ap, arg);
	else if (spcf == 's')
		result = print_type_s(ap, arg);
	else if (spcf == 'u')
		result = print_type_u(ap, arg);
	else if (spcf == 'x')
		result = print_type_x(ap, arg);
	else if (spcf == 'X')
		result = print_type_x_upper(ap, arg);
	else if (spcf == 'p')
		result = print_type_p(ap, arg);
	else if (spcf == '%')
		result = print_type_percent(arg);
	return (result);
}
