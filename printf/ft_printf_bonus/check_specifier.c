/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:35:39 by ylee              #+#    #+#             */
/*   Updated: 2020/11/20 10:49:20 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_specifier(char c)
{
	char	*specifiers;

	specifiers = "cspdiuxX%nfge";
	while (*specifiers)
	{
		if (c == *specifiers)
			return ((int)c);
		specifiers++;
	}
	return (0);
}
