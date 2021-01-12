/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:47:54 by ylee              #+#    #+#             */
/*   Updated: 2020/12/08 14:02:55 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_d(va_list ap, t_arg *arg)
{
	char			*result;
	char			*tmp;
	long long int	llnum;
	long int		lnum;
	int				num;
	short int		snum;
	signed char		scnum;

	tmp = NULL;
	if (arg->specifier != 'd' && arg->specifier != 'i')
		return (0);
	llnum = va_arg(ap, long long int);
	lnum = (long int)llnum;
	num = (int)llnum;
	scnum = (signed char)llnum;
	snum = (short int)llnum;
	if (arg->hh == 1)
		result = ft_itoa((int)scnum);
	else if (arg->h == 1)
		result = ft_itoa((int)snum);
	else if (arg->ll == 1)
		result = ft_lltoa(llnum);
	else if (arg->l == 1)
		result = ft_ltoa(lnum);
	else
		result = ft_itoa(num);
	if ((arg->plus == 1 || arg->space == 1) && arg->dot == 1 && num == 0)
		result[0] = '\0';
	if (arg->plus == 1 && result[0] != '-')
		tmp = ft_strjoin("+", result);
	else if (arg->space == 1 && result[0] != '-')
		tmp = ft_strjoin(" ", result);
	if (tmp != NULL)
	{
		free(result);
		result = tmp;
	}
	arg->tmp_len = ft_strlen(result);
	result = apply_precision(arg, result);
	result = apply_width(arg, result);
	return (result);
}
