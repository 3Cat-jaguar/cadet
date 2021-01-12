/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arg_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:16:13 by ylee              #+#    #+#             */
/*   Updated: 2020/12/01 10:09:59 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_arg	*ft_init_arg_list(t_arg *arg)
{
	if (!arg)
		return (0);
	arg->dash = 0;
	arg->plus = 0;
	arg->space = 0;
	arg->sharp = 0;
	arg->zero = 0;
	arg->width = 0;
	arg->dot = 0;
	arg->precision = 0;
	arg->l = 0;
	arg->ll = 0;
	arg->h = 0;
	arg->hh = 0;
	arg->specifier = 0;
	arg->tmp_len = 0;
	return (arg);
}
