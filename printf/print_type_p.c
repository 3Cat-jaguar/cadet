/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:08:04 by ylee              #+#    #+#             */
/*   Updated: 2020/12/01 09:53:35 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_p(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 'p')
		return (0);
	result = ft_lltoa_base16(va_arg(ap, long long));
	arg->tmp_len = ft_strlen(result);
	result = apply_precision(arg, result);
	result = ft_strjoin("0x", result);
	arg->tmp_len = arg->tmp_len + 2;
	result = apply_width(arg, result);
	return (result);
}
