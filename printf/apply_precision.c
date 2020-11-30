/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee </var/mail/ylee>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:38:38 by ylee              #+#    #+#             */
/*   Updated: 2020/11/30 14:46:41 by ylee             ###   ########.fr       */
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
	if (str[0] == '-')
		arg->width = arg->width + 1;
	else if (str[0] == '0' && str[1] == '\0')
		str[0] = '\0';
	arg->dash = 0;
	arg->zero = 1;
	result = apply_width(arg, str);
	arg->zero = 0;
	arg->dash = real_dash;
	arg->width = real_width;
	return (result);
}

char	*apply_precision(t_arg *arg, char *str)
{
	char	*result;
	int		str_len;
	int		final_len;
	char	spcf;

	if (arg->dot != 1)
		return (str);
	str_len = ft_strlen(str);
	final_len = arg->precision;
	spcf = arg->specifier;
	if (final_len < 0)
	{
		arg->dash = 1;
		final_len = -final_len;
	}
	if (spcf == 'd' || spcf == 'i' || spcf == 'u' || spcf == 'x' || spcf == 'X')
		arg->zero = 0;
	if (spcf == 'd' || spcf == 'i' || spcf == 'u' || spcf == 'x' || spcf == 'X' || spcf == 'p')
		result = apply_prcs_type_num(arg, str);
	else if (final_len < str_len)
	{
		arg->final_len = final_len;
		result = (char *)malloc(sizeof(char) * (final_len + 1));
		ft_strlcpy(result, str, final_len + 1);
		free(str);
		str = NULL;
	}
	else
		return (str);
	return (result);
}
