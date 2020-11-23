/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:55:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/23 12:08:26 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*apply_width(t_arg *arg, char *str)
{
	int		str_len;
	int		final_len;
	int		diff;
	char	*add_str;
	char	*result;

	str_len = ft_strlen(str);
	final_len = arg->width;
	if (final_len <= str_len)
		return (str);
	diff = final_len - str_len;
	add_str = (char *)malloc(sizeof(char) * (diff + 1));
	add_str[diff] = '\0';
	while (--diff >= 0)
		add_str[diff] = ' ';
	if (arg->dash == 1)
		result = ft_strjoin(str, add_str);
	else
		result = ft_strjoin(add_str, str);
	free(add_str);
	add_str = NULL;
	free(str);
	str = NULL;
	return (result);
}
