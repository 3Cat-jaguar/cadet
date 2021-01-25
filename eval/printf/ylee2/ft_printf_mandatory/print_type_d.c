/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:47:54 by ylee              #+#    #+#             */
/*   Updated: 2021/01/13 15:18:54 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_type_d_bonus(t_arg *arg, long long int llnum)
{
	char			*result;
	long int		lnum;
	short int		snum;
	signed char		scnum;

	result = NULL;
	lnum = (long int)llnum;
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
	return (result);
}

char	*check_d_flags(t_arg *arg, char *result, int num)
{
	char	*tmp;

	tmp = NULL;
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
	return (result);
}

char	*print_type_d(va_list ap, t_arg *arg)
{
	char			*result;
	long long int	llnum;
	int				num;

	if (arg->specifier != 'd' && arg->specifier != 'i')
		return (0);
	llnum = va_arg(ap, long long int);
	num = (int)llnum;
	if (arg->hh == 1 || arg->h == 1 || arg->ll == 1 || arg->l == 1)
		result = print_type_d_bonus(arg, llnum);
	else
		result = ft_itoa(num);
	result = check_d_flags(arg, result, num);
	arg->tmp_len = ft_strlen(result);
	result = apply_precision(arg, result);
	result = apply_width(arg, result);
	return (result);
}
