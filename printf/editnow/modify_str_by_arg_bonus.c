/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str_by_arg_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:43:04 by ylee              #+#    #+#             */
/*   Updated: 2021/02/01 15:33:27 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*modify_str_by_arg_bonus(va_list ap, t_arg *arg)
{
	char	*result;
	char	spcf;

	result = NULL;
	spcf = (char)(arg->specifier);
	if (spcf == 'n')
		result = print_type_n(ap, arg);
	else if (spcf == 'f')
		result = print_type_f(ap, arg);
	else if (spcf == 'g')
		result = print_type_g(ap, arg);
	else if (spcf == 'e')
		result = print_type_e(ap, arg);
	else if (spcf == 'o')
		result = print_type_o(ap, arg);
	return (result);
}
