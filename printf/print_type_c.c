/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:51:27 by ylee              #+#    #+#             */
/*   Updated: 2020/11/18 16:16:42 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_c(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 'c')
		return (0);
	result = (char *)ft_calloc(2, sizeof(char));
	result[0] = (char)va_arg(ap, int);
	return (result);
}
