/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:53:43 by ylee              #+#    #+#             */
/*   Updated: 2020/11/18 16:17:23 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_s(va_list ap, t_arg *arg)
{
	char	*result;

	if (arg->specifier != 's')
		return (0);
	result = va_arg(ap, char *);
	if (result == NULL)
		result = ft_strdup("(null)");
	else
		result = ft_strdup(result);
	return (result);
}
