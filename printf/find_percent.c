/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:35:45 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 11:26:55 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*find_percent(va_list ap, char *str, int *idx)
{
	int		i;
	t_arg	*arg;

	i = *idx;
	if (str[i++] != '%')
		return (0);
	if (!(arg = ft_init_arg_list()))
		return (0);
	while (check_flags(arg, str[i]) == 1)
		i++;
	while ((arg->specifier = check_specifier(str[i])) == 1)
	{
		if (str[i] == '.')
		{
			arg->dot = 1;
			i++;
		}
		else if ((str[i] >= '1' && str[i] <= '9') || str[i] == '*')
			i = i + width_or_precision(ap, arg, &str[i])
		else if (str[i] == 'l' || str[i] == 'h')
			i = i + check_length(arg, &str[i]);
	}
	return (modify_str_by_arg(ap, arg));
}
