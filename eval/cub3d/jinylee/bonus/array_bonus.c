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

#include "cub3d_bonus.h"

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

void		crossshot(t_game *s)
{
	int	i;
	int	j;

	i = s->map.w / 2 - 15;
	j = s->map.h / 2;
	while (i < s->map.w / 2 + 15)
	{
		if (i < s->map.w / 2 - 5 || i > s->map.w / 2 + 5)
			s->buf[j][i] = 0xffffff;
		i++;
	}
	i = s->map.w / 2;
	j = s->map.h / 2 - 15;
	while (j < s->map.h / 2 + 15)
	{
		if (j < s->map.h / 2 - 5 || j > s->map.h / 2 + 5)
			s->buf[j][i] = 0xffffff;
		j++;
	}
}
