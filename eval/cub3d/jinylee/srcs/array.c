/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:27:52 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:28:07 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_arrlen(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void		free_arr(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = 0;
		i++;
	}
	free(array);
}
