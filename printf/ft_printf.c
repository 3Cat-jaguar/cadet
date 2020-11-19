/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:43:39 by ylee              #+#    #+#             */
/*   Updated: 2020/11/19 15:17:06 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		start;
	t_arg	*arg;
	char	*result[4];

	idx = 0;
	start = 0;
	va_start(ap, str);
	arg = NULL;
	result[0] = ft_strdup("");
	result[3] = ft_strdup(str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			result[3][idx] = '\0';
			result[2] = ft_strjoin(result[0], &result[3][start]);
			free(result[0]);
			result[0] = NULL;
			result[0] = ft_strdup(result[2]);
			free(result[2]);
			result[2] = NULL;
			result[1] = find_percent(ap, arg, (char *)str, &idx);
			start = idx + 1;
			result[2] = ft_strjoin(result[0], result[1]);
			free(result[0]);
			result[0] = NULL;
			result[0] = ft_strdup(result[2]);
			free(result[2]);
			result[2] = NULL;
			free(result[1]);
			result[1] = NULL;
		}
		idx++;
	}
	result[2] = ft_strjoin(result[0], &result[3][start]);
	free(result[0]);
	result[0] = NULL;
	result[0] = ft_strdup(result[2]);
	free(result[2]);
	result[2] = NULL;
	write(1, result[0], ft_strlen(result[0]));
	free(result[0]);
	result[0] = NULL;
	va_end(ap);
	return (0);
}
