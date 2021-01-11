/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:29:57 by ylee              #+#    #+#             */
/*   Updated: 2021/01/11 15:51:41 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_f(va_list ap, t_arg *arg)
{
	char	*result;
	float	num;

	result = NULL;
	num = 0;
	if (arg->specifier == 'f')
		num = (float)va_arg(ap, double);
	result = testf(num);
	arg->tmp_len = ft_strlen(result);
	return (result);
}
