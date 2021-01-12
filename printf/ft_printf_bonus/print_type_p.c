/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:08:04 by ylee              #+#    #+#             */
/*   Updated: 2020/12/08 14:36:08 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_p(va_list ap, t_arg *arg)
{
	char	*result;
	char	*tmp;

	if (arg->specifier != 'p')
		return (0);
	result = ft_ulltoa_base16(va_arg(ap, unsigned long long));
	arg->tmp_len = ft_strlen(result);
	result = apply_precision(arg, result);
	tmp = ft_strjoin("0x", result);
	free(result);
	result = NULL;
	result = tmp;
	arg->tmp_len = arg->tmp_len + 2;
	result = apply_width(arg, result);
	return (result);
}
