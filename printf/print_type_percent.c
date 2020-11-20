/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:51:27 by ylee              #+#    #+#             */
/*   Updated: 2020/11/20 13:09:56 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_percent(t_arg *arg)
{
	char	*result;

	if (arg->specifier != '%')
		return (0);
	result = ft_strdup("%");
	return (result);
}
