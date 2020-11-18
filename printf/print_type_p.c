/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:08:04 by ylee              #+#    #+#             */
/*   Updated: 2020/11/18 16:18:34 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_p(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 'p')
		return (0);
	result = ft_lltoa_base16(va_arg(ap, long long));
	result = ft_strjoin("0x", result);
	return (result);
}
