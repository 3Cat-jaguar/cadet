/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:55:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/23 10:08:03 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*apply_width(t_arg *arg, char *str)
{
	int		str_len;
	int		final_len;
	char	*result;

	str_len = ft_strlen(str);
	final_len = arg->width;
	if (final_len <= str_len)
		return (str);
	result = (char *)ft_malloc(sizeof(char) * (final_len + 1));
	while (final_len >= 0)
	{
		if (str_len >= 0)
			result(final_len--) = str(str_len--);
		else
			result(rinal_len--) = ' ';
	}
	free(str);
	str = NULL;
	return (result);
}
