/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:43:39 by ylee              #+#    #+#             */
/*   Updated: 2020/11/20 10:45:15 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	join_str_and_free(char **result, char *str)
{
	result[2] = ft_strjoin(result[0], str);
	free(result[0]);
	result[0] = NULL;
	result[0] = ft_strdup(result[2]);
	free(result[2]);
	result[2] = NULL;
}

void	init_variables(int *idx, int *start, t_arg **arg, char **result)
{
	*idx = 0;
	*start = 0;
	*arg = NULL;
	result[0] = ft_strdup("");
}

void	ending(char **result, int start, va_list ap)
{
	join_str_and_free(result, &result[3][start]);
	write(1, result[0], ft_strlen(result[0]));
	free(result[0]);
	result[0] = NULL;
	free(result[3]);
	result[3] = NULL;
	va_end(ap);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		start;
	t_arg	*arg;
	char	*result[4];

	init_variables(&idx, &start, &arg, result);
	result[3] = ft_strdup(str);
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			result[3][idx] = '\0';
			join_str_and_free(result, &result[3][start]);
			result[1] = find_percent(ap, arg, (char *)str, &idx);
			start = idx + 1;
			join_str_and_free(result, result[1]);
			free(result[1]);
			result[1] = NULL;
		}
		idx++;
	}
	ending(result, start, ap);
	return (0);
}
