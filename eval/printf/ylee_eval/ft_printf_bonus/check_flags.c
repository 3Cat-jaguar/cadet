/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:38:21 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 13:52:15 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_flags(t_arg *arg, char c)
{
	if (c == '-')
		arg->dash = 1;
	else if (c == '+')
		arg->plus = 1;
	else if (c == ' ')
		arg->space = 1;
	else if (c == '#')
		arg->sharp = 1;
	else if (c == '0')
		arg->zero = 1;
	else
		return (0);
	return (1);
}
