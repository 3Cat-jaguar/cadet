/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:25:20 by ylee              #+#    #+#             */
/*   Updated: 2020/10/27 09:35:37 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int		result;
	int		fd;
	char	*str;

	result = 1;
	str = NULL;
	fd = open("test.txt", O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &str);
		printf("main\n");
		printf("gnl result : %d / ", result);
		printf("read line : %s\n", str);
		printf("\n");
		if (result == 0)
		{
			free(str);
			str = NULL;
			return (0);
		}
		else if (result == 1)
		{
			free(str);
			str = NULL;
		}
	}
	return (0);
}
