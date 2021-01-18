/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:29:57 by ylee              #+#    #+#             */
/*   Updated: 2021/01/18 13:02:15 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_f(va_list ap, t_arg *arg)
{
	char	*result;
	double	num;

	result = NULL;
	num = 0;
	if (arg->specifier == 'f')
		num = va_arg(ap, double);
	result = testf(num);
	arg->tmp_len = ft_strlen(result);
	return (result);
}
