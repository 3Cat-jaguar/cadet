/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:35:45 by ylee              #+#    #+#             */
/*   Updated: 2021/01/13 15:03:58 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*modify_str(va_list ap, t_arg *arg)
{
	if (arg->specifier == 'n' || arg->specifier == 'f'\
			|| arg->specifier == 'g' || arg->specifier == 'e')
		return (modify_str_by_arg_bonus(ap, arg));
	return (modify_str_by_arg(ap, arg));
}

char	*find_percent(va_list ap, t_arg *arg, char *str, int *idx)
{
	int		i;

	i = *idx;
	if (str[i++] != '%')
		return (0);
	if (!(arg = ft_init_arg_list(arg)))
		return (0);
	while (check_flags(arg, str[i]) == 1)
		i++;
	while (str[i] && (arg->specifier = check_specifier(str[i])) == 0)
	{
		if (str[i] == '.')
			arg->dot = 1;
		else if ((str[i] >= '1' && str[i] <= '9') || str[i] == '*')
			i = i + width_or_precision(ap, arg, &str[i]) - 1;
		else if (str[i] == 'l' || str[i] == 'h')
			i = i + check_length(arg, &str[i]) - 1;
		i++;
	}
	if (arg->specifier == 0)
		return (ft_strdup(&str[*idx]));
	*idx = i;
	return (modify_str(ap, arg));
}
