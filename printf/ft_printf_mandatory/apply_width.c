/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:55:41 by ylee              #+#    #+#             */
/*   Updated: 2020/12/07 14:16:24 by ylee             ###   ########.fr       */
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
	free(str);
	str = NULL;
	return (result);
}

char	*with_zero(char *result, char *str, int final_len, int str_len)
{
	while (--final_len >= 0)
	{
		if (--str_len > 0)
			result[final_len] = str[str_len];
		else if (str_len == 0 && (result[0] == 'd' || result[0] == 'i') 
				&& (str[0] == '-' || str[0] == '+' || str[0] == ' '))
		{
			result[final_len] = '0';
			result[0] = str[0];
		}
		else if (str_len == 0)
			result[final_len] = str[str_len];
		else if (result[final_len] != '-' && result[final_len] != '+' && result[final_len] != ' ')
			result[final_len] = '0';
	}
	free(str);
	str = NULL;
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
	free(str);
	str = NULL;
	return (result);
}

char	*apply_width(t_arg *arg, char *str)
{
	int		str_len;
	int		final_len;
	char	*result;

	str_len = arg->tmp_len;
	if (arg->specifier == 'c')
		str_len = 1;
	final_len = arg->width;
	if (final_len < 0)
	{
		arg->dash = 1;
		final_len = -final_len;
	}
	if (final_len <= str_len)
		return (str);
	arg->tmp_len = final_len;
	result = (char *)ft_calloc(final_len + 1, sizeof(char));
	result[0] = (char)arg->specifier;
	if (arg->dash == 1)
		result = with_dash(result, str, final_len, str_len);
	else if (arg->zero == 1)
		result = with_zero(result, str, final_len, str_len);
	else
		result = without(result, str, final_len, str_len);
	return (result);
}
