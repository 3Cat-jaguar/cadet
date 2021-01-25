/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:39:18 by ylee              #+#    #+#             */
/*   Updated: 2020/10/08 09:39:54 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int p)
{
	if (p >= 32 && p <= 126)
		return (1);
	else
		return (0);
}