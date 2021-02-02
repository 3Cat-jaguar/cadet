/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:40:53 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 14:18:05 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_length(t_arg *arg, char *str)
{
	if (*str == 'l' && *(str + 1) != 'l')
	{
		arg->l = 1;
		return (1);
	}
	else if (*str == 'l' && *(str + 1) == 'l')
	{
		arg->ll = 1;
		return (2);
	}
	else if (*str == 'h' && *(str + 1) != 'h')
	{
		arg->h = 1;
		return (1);
	}
	else if (*str == 'h' && *(str + 1) == 'h')
	{
		arg->hh = 1;
		return (2);
	}
	return (0);
}
