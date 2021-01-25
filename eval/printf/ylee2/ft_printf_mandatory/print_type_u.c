/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:56:19 by ylee              #+#    #+#             */
/*   Updated: 2021/01/13 12:08:59 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*printf_type_u_bonus(t_arg *arg, unsigned long long int usll)
{
	char				*result;
	unsigned long int	usl;
	unsigned short int	uss;
	unsigned char		usc;

	result = NULL;
	usl = (unsigned long int)usll;
	uss = (unsigned short int)usll;
	usc = (unsigned char)usll;
	if (arg->hh == 1)
		result = ft_uitoa((unsigned int)usc);
	else if (arg->h == 1)
		result = ft_uitoa((unsigned int)uss);
	else if (arg->ll == 1)
		result = ft_ulltoa(usll);
	else if (arg->l == 1)
		result = ft_ultoa(usl);
	return (result);
}

char	*print_type_u(va_list ap, t_arg *arg)
{
	char					*result;
	unsigned long long int	usll;
	unsigned int			usi;

	if (arg->specifier != 'u')
		return (0);
	usll = va_arg(ap, unsigned long long int);
	usi = (unsigned int)usll;
	if (arg->hh == 1 || arg->h == 1 || arg->l == 1 || arg->ll == 1)
		result = printf_type_u_bonus(arg, usll);
	else
		result = ft_uitoa(usi);
	arg->tmp_len = ft_strlen(result);
	result = apply_precision(arg, result);
	result = apply_width(arg, result);
	return (result);
}
