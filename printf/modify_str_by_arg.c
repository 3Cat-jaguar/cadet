/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str_by_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:43:04 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 15:23:37 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*modify_str_by_arg(va_list ap, t_arg *arg)
{
	char	*result;
	char	spcf;

	if (!(result = (char *)ft_calloc(25, sizeof(char))))
		return (0);
	spcf = (char)(arg->specifier);
	if (spcf == 'd' || spcf == 'i')
		result = ft_itoa(va_arg(ap, int));
	else if (spcf == 'c')
		*result = (char)va_arg(ap, int);
	else if (spcf == 's')
	{
		result = va_arg(ap, char *);
		if (result == NULL)
			result = ft_strdup("(null)");
	}
	else if (spcf == 'u')
		ft_uitoa(va_arg(ap, unsigned int), &result);
	else if (spcf == 'x')
		ft_itoa_base16(va_arg(ap, unsigned int), &result);
	else if (spcf == 'X')
	{
		ft_itoa_base16(va_arg(ap, unsigned int), &result);
		ft_toupper_str(&result);
	}
	else if (spcf == 'p')
	{
		ft_lltoa_base16(va_arg(ap, long long), &result);
		result = ft_strjoin("0x", result);
	}
	free(arg);
	arg = NULL;
	return (result);
}
