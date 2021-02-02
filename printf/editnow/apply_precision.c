/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:38:38 by ylee              #+#    #+#             */
/*   Updated: 2021/02/01 15:50:40 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*apply_prcs_type_num(t_arg *arg, char *str)
{
	int		real_width;
	int		real_dash;
	char	*result;

	real_width = arg->width;
	real_dash = arg->dash;
	arg->width = arg->precision;
	if (str[0] == '-' || arg->plus == 1 || arg->space == 1)
		arg->width = arg->width + 1;
	else if (str[0] == '0' && str[1] == '\0')
	{
		str[0] = '\0';
		arg->tmp_len = 0;
	}
	arg->dash = 0;
	arg->zero = 1;
	result = apply_width(arg, str);
	arg->zero = 0;
	arg->dash = real_dash;
	arg->width = real_width;
	return (result);
}

char	*apply_prcs_type_else(t_arg *arg, char *str, int final_len)
{
	char	*result;

	arg->tmp_len = final_len;
	result = (char *)malloc(sizeof(char) * (final_len + 1));
	ft_strlcpy(result, str, final_len + 1);
	free(str);
	str = NULL;
	return (result);
}

char	*apply_precision(t_arg *arg, char *str)
{
	char	*result;
	int		str_len;
	int		final_len;
	char	spcf;

	if (arg->dot != 1 || arg->precision < 0)
		return (str);
	str_len = arg->tmp_len;
	final_len = arg->precision;
	spcf = arg->specifier;
	if (spcf == 'd' || spcf == 'i' || spcf == 'u' || spcf == 'x' || spcf == 'X' || spcf == 'o')
		arg->zero = 0;
	if (spcf == 'd' || spcf == 'i' || spcf == 'u' \
			|| spcf == 'x' || spcf == 'X' || spcf == 'p' || spcf == 'o')
		result = apply_prcs_type_num(arg, str);
	else if (final_len < str_len)
		result = apply_prcs_type_else(arg, str, final_len);
	else
		return (str);
	return (result);
}
