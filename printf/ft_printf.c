/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:43:39 by ylee              #+#    #+#             */
/*   Updated: 2021/01/11 15:51:57 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_variables(int *idx, int *start, t_arg **arg)
{
	*idx = 0;
	*start = 0;
	if (!(*arg = (t_arg *)malloc(sizeof(t_arg))))
		*arg = NULL;
	*arg = ft_init_arg_list(*arg);
	(*arg)->final_len = 0;
}

void	write_str(t_arg *arg, char *str)
{
	write(1, str, arg->tmp_len);
	arg->final_len = arg->final_len + arg->tmp_len;
}

int		ending(char **result, int start, va_list ap, t_arg *arg)
{
	int		len;

	len = ft_strlen(&result[3][start]);
	write(1, &result[3][start], len);
	arg->final_len = arg->final_len + len;
	free(result[3]);
	result[3] = NULL;
	va_end(ap);
	len = arg->final_len;
	free(arg);
	arg = NULL;
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		start;
	t_arg	*arg;
	char	*result[4];

	init_variables(&idx, &start, &arg);
	result[3] = ft_strdup(str);
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			result[3][idx] = '\0';
			arg->tmp_len = ft_strlen(&result[3][start]);
			write_str(arg, &result[3][start]);
			result[1] = find_percent(ap, arg, (char *)str, &idx);
			write_str(arg, result[1]);
			start = idx + 1;
			free(result[1]);
			result[1] = NULL;
		}
		idx++;
	}
	return (ending(result, start, ap, arg));
}
