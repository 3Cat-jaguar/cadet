/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:43:39 by ylee              #+#    #+#             */
/*   Updated: 2020/11/30 16:25:25 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	init_variables(int *idx, int *start, t_arg **arg, char **result)
{
	*idx = 0;
	*start = 0;
	if (!(*arg = (t_arg *)malloc(sizeof(t_arg))))
		*arg = NULL;
	*arg = ft_init_arg_list(*arg);
	result[0] = ft_strdup("");
}

int		ending(char **result, int start, va_list ap, int final_len)
{
	int		len;

	len = ft_strlen(&result[3][start]);
	if (len != 0)
		write(1, &result[3][start], len);
	final_len += len;
	free(result[0]);
	result[0] = NULL;
	free(result[3]);
	result[3] = NULL;
	va_end(ap);
	return (final_len);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		start;
	t_arg	*arg;
	char	*result[4];
	int		tmp_len;
	int		final_len;

	init_variables(&idx, &start, &arg, result);
	tmp_len = 0;
	final_len = 0;
	result[3] = ft_strdup(str);
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			result[3][idx] = '\0';
			tmp_len = ft_strlen(&result[3][start]);
			if (tmp_len != 0)
				write(1, &result[3][start], tmp_len);
			final_len += tmp_len;
			result[1] = find_percent(ap, arg, (char *)str, &idx);
			tmp_len = arg->final_len;
			if (tmp_len != 0)
				write(1, result[1], tmp_len);
			final_len += tmp_len;
			start = idx + 1;
			free(result[1]);
			result[1] = NULL;
		}
		idx++;
	}
	final_len = ending(result, start, ap, final_len);
	return (final_len);
}
