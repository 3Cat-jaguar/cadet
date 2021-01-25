/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:00:39 by ylee              #+#    #+#             */
/*   Updated: 2021/01/13 13:57:41 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_x_bonus(t_arg *arg, unsigned long long int usll)
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
		result = ft_uitoa_base16((unsigned int)usc);
	else if (arg->h == 1)
		result = ft_uitoa_base16((unsigned int)uss);
	else if (arg->ll == 1)
		result = ft_ulltoa_base16(usll);
	else if (arg->l == 1)
		result = ft_ultoa_base16(usl);
	return (result);
}

char	*check_zero(t_arg *arg, unsigned int usi, char *result, char *tmp)
{
	if (arg->zero == 1)
	{
		if (arg->sharp == 1 && usi != 0 && arg->width >= 2)
			arg->width = arg->width - 2;
		result = apply_width(arg, result);
		if (arg->sharp == 1 && usi != 0)
		{
			tmp = ft_strjoin("0x", result);
			arg->tmp_len = arg->tmp_len + 2;
			free(result);
			result = tmp;
		}
	}
	else
	{
		if (arg->sharp == 1 && usi != 0)
		{
			tmp = ft_strjoin("0x", result);
			arg->tmp_len = arg->tmp_len + 2;
			free(result);
			result = tmp;
		}
		result = apply_width(arg, result);
	}
	return (result);
}

char	*print_type_x(va_list ap, t_arg *arg)
{
	char					*result;
	char					*tmp;
	unsigned long long int	usll;
	unsigned int			usi;

	tmp = NULL;
	if (arg->specifier != 'x')
		return (0);
	usll = va_arg(ap, unsigned long long int);
	usi = (unsigned int)usll;
	if (arg->hh == 1 || arg->h == 1 || arg->ll == 1 || arg->l == 1)
		result = print_type_x_bonus(arg, usll);
	else
		result = ft_uitoa_base16(usi);
	arg->tmp_len = ft_strlen(result);
	result = apply_precision(arg, result);
	arg->tmp_len = ft_strlen(result);
	if (arg->width < 0)
	{
		arg->dash = 1;
		arg->width = arg->width * (-1);
	}
	result = check_zero(arg, usi, result, tmp);
	return (result);
}
