/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee </var/mail/ylee>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:38:38 by ylee              #+#    #+#             */
/*   Updated: 2020/11/24 11:48:22 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	if (spcf != 'c' && spcf != 's' && spcf != 'p')
		arg->zero = 0;
	if (final_len < str_len && arg->specifier == 's')
	{
		result = (char *)malloc(sizeof(char) * (final_len + 1));
		ft_strlcpy(result, str, final_len + 1);
		free(str);
		str = NULL;
		str = result;
	}
	return (str);
}
