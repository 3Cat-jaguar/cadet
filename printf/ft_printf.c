/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:43:39 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 16:27:18 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	t_arg	*arg;
	char	*result;

	idx = 0;
	va_start(ap, str);
	arg = NULL;
	while (str[idx])
	{
		if (str[idx] != '%')
			write(1, &str[idx], 1);
		else if (str[idx] == '%')
		{
			result = find_percent(ap, arg, (char *)str, &idx);
			write(1, result, ft_strlen(result));
			free(result);
			result = NULL;
		}
		idx++;
	}
	va_end(ap);
	return (0);
}
