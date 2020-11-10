/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:20:37 by ylee              #+#    #+#             */
/*   Updated: 2020/11/10 15:51:17 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	check_specifier(char c)
{
	char	*specifiers;

	specifiers = "cspdiuxXnfge";
	while (*specifiers)
	{
		if (c == *specifiers)
			return (c);
		specifiers++;
	}
	return (1);
}

int		check_flags(t_arg **arg, char c)
{
	t_arg	*tmp;

	tmp = *arg;
	if (c == '-')
		tmp->dash = 1;
	else if (c == '+')
		tmp->plus = 1;
	else if (c == ' ')
		tmp->space = 1;
	else if (c == '#')
		tmp->sharp = 1;
	else if (c == '0')
		tmp->zero = 1;
	else
		return (0);
	return (1);
}

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

int		set_arg_list(va_list star, t_arg **arg, char *str, int idx)
{
	t_arg	*tmp;

	tmp = *arg;
	if (str[idx] != '%')
		return (idx);
	idx++;
	while ((tmp->specifier = check_specifier(str[idx])) == 1)
	{
		while (check_flags(&tmp, str[idx]) == 1)
			idx++;
		if (str[idx] >= '1' && str[idx] <= '9' && tmp->dot == 0)
			tmp->width = ft_atoi(&str[idx]);
		else if (str[idx] >= '1' && str[idx] <= '9' && tmp->dot == 1)
			tmp->precision = ft_atoi(&str[idx]);
		while (str[idx] >= '0' && str[idx] <= '9')
			idx++;
		if (str[idx] == '*' && tmp->dot == 0)
			tmp->width = va_arg(star, int);
		else if (str[idx] == '*' && tmp->dot == 1)
			tmp->precision = va_arg(star, int);
		if (str[idx] == '.')
			tmp->dot = 1;
		if  (str[idx] == '.' || str[idx] == '*')
			idx++;
		idx = idx + check_length(tmp, &str[idx]);
	}
	return (idx);
}

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	char			*result;
	int				idx;
	t_arg			*tmp_arg;

	idx = 0;
	tmp_arg = ft_init_arg_list();
	if (!tmp_arg)
		return (0);
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] != '%')
			write (1, &str[idx], 1);
		else if (str[idx] == '%')
		{
			tmp_arg = ft_init_arg_list();
			idx = set_arg_list(ap, &tmp_arg, (char *)str, idx);
			printf("\n");
			printf("flag : dash-%d plus-%d space-%d sharp-%d zero-%d\n", tmp_arg->dash, tmp_arg->plus, tmp_arg->space, tmp_arg->sharp, tmp_arg->zero);
			printf("width : width-%d\n", tmp_arg->width);
			printf("dot precision : dot-%d precision-%d\n", tmp_arg->dot, tmp_arg->precision);
			printf("length : l-%d ll-%d h-%d hh-%d\n", tmp_arg->l, tmp_arg->ll, tmp_arg->h, tmp_arg->hh);
			printf("specifier : specifier-%c\n", tmp_arg->specifier);

			if (str[idx] == 'd' || str[idx] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (str[idx] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (str[idx] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (str[idx] == 'u')
				ft_put_unsigned_int_fd(va_arg(ap, unsigned int), 1);
			else if (str[idx] == 'x')
			{
				result = (char *)ft_calloc(15, sizeof(char));
				ft_itoa_base16(va_arg(ap, unsigned int), &result);
				ft_putstr_fd(result, 1);
				free(result);
				result = NULL;
			}
			else if (str[idx] == 'X')
			{
				result = (char *)ft_calloc(15, sizeof(char));
				ft_itoa_base16(va_arg(ap, unsigned int), &result);
				ft_toupper_str(&result);
				ft_putstr_fd(result, 1);
				free(result);
				result = NULL;
			}
			else if (str[idx] == 'p')
			{
				result = (char *)ft_calloc(25, sizeof(char));
				ft_lltoa_base16(va_arg(ap, long long), &result);
				ft_putstr_fd("0x", 1);
				ft_putstr_fd(result, 1);
				free(result);
				result = NULL;
			}

		}
		idx++;
	}
	va_end(ap);
	return (0);
}
