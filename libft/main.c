/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:50:00 by ylee              #+#    #+#             */
/*   Updated: 2020/10/04 17:08:43 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_strlen(const char *s);

int		main(void)
{
	const char *s;

	s = "hello world";
	printf("%lu\n", strlen(s));
	printf("%lu\n", ft_strlen(s));
	return (0);
}
