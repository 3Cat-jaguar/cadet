/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:00:39 by ylee              #+#    #+#             */
/*   Updated: 2021/02/01 15:39:34 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_o_bonus(t_arg *arg, unsigned long long int usll)
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
		result = ft_uitoa_base8((unsigned int)usc);
	else if (arg->h == 1)
		result = ft_uitoa_base8((unsigned int)uss);
	else if (arg->ll == 1)
		result = ft_ulltoa_base8(usll);
	else if (arg->l == 1)
		result = ft_ultoa_base8(usl);
	return (result);
}

char	*check_zero_o(t_arg *arg, unsigned int usi, char *result, char *tmp)
{
	if (arg->zero == 1)
	{
		if (arg->sharp == 1 && usi != 0 && arg->width >= 1)
			arg->width = arg->width - 1;
		result = apply_width(arg, result);
		if (arg->sharp == 1 && usi != 0)
		{
			tmp = ft_strjoin("0", result);
			arg->tmp_len = arg->tmp_len + 1;
			free(result);
			result = tmp;
		}
	}
	else
	{
		if (arg->sharp == 1 && usi != 0)
		{
			tmp = ft_strjoin("0", result);
			arg->tmp_len = arg->tmp_len + 1;
			free(result);
			result = tmp;
		}
		result = apply_width(arg, result);
	}
	return (result);
}

char	*print_type_o(va_list ap, t_arg *arg)
{
	char					*result;
	char					*tmp;
	unsigned long long int	usll;
	unsigned int			usi;

	tmp = NULL;
	if (arg->specifier != 'o')
		return (0);
	usll = va_arg(ap, unsigned long long int);
	usi = (unsigned int)usll;
	if (arg->hh == 1 || arg->h == 1 || arg->ll == 1 || arg->l == 1)
		result = print_type_o_bonus(arg, usll);
	else
		result = ft_uitoa_base8(usi);
	arg->tmp_len = ft_strlen(result);
	result = apply_precision(arg, result);
	arg->tmp_len = ft_strlen(result);
	if (arg->width < 0)
	{
		arg->dash = 1;
		arg->width = arg->width * (-1);
	}
	result = check_zero_o(arg, usi, result, tmp);
	return (result);
}
