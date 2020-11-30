/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:55:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/30 15:35:34 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*with_dash(char *result, char *str, int final_len, int str_len)
{
	int		idx;

	idx = 0;
	while (idx < final_len)
	{
		if (idx < str_len)
			result[idx] = str[idx];
		else
			result[idx] = ' ';
		idx++;
	}
	return (result);
}

char	*with_zero(char *result, char *str, int final_len, int str_len)
{
	while (--final_len >= 0)
	{
		if (--str_len >= 0 && str[str_len] != '-')
			result[final_len] = str[str_len];
		else
			result[final_len] = '0';
		if (str[0] == '-')
			result[0] = '-';
	}
	return (result);
}

char	*without(char *result, char *str, int final_len, int str_len)
{
	while (--final_len >= 0)
	{
		if (--str_len >= 0)
			result[final_len] = str[str_len];
		else
			result[final_len] = ' ';
	}
	return (result);
}

char	*apply_width(t_arg *arg, char *str)
{
	int		str_len;
	int		final_len;
	char	*result;

	str_len = ft_strlen(str);
	if (arg->specifier == 'c')
		str_len = 1;
	final_len = arg->width;
	if (final_len < 0)
	{
		arg->dash = 1;
		final_len = -final_len;
	}
	if (final_len <= str_len)
	{
		arg->final_len = str_len;
		return (str);
	}
	arg->final_len = final_len;
	result = (char *)ft_calloc(final_len + 1, sizeof(char));
	if (arg->dash == 1)
		result = with_dash(result, str, final_len, str_len);
	else if (arg->zero == 1)
		result = with_zero(result, str, final_len, str_len);
	else
		result = without(result, str, final_len, str_len);
	free(str);
	str = NULL;
	return (result);
}
