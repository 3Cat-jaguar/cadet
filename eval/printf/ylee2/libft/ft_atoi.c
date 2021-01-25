/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:51:46 by ylee              #+#    #+#             */
/*   Updated: 2020/10/20 10:10:31 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	check_init(const char *str, int *i, int *checkn)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*checkn *= -1;
		*i = *i + 1;
	}
}

int			ft_atoi(const char *str)
{
	int					i;
	int					checkn;
	unsigned long long	num;

	i = 0;
	checkn = 1;
	num = 0;
	check_init(str, &i, &checkn);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > 9223372036854775807)
			break ;
		i++;
	}
	if (num > 9223372036854775807)
	{
		if (checkn == -1)
			return (0);
		else if (checkn == 1)
			return (-1);
	}
	num = num * checkn;
	return ((int)num);
}
