/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:05:56 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/25 23:06:15 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void		calculate_sf_dist(double height, double *r)
{
	int	i;

	i = 0;
	while (i < height)
	{
		r[i] = (height / (2. * (double)i - height));
		i++;
	}
}

void			make_tables(t_game *info)
{
	calculate_sf_dist(info->map.h, info->r_dist);
}

int				ft_cnt(t_game *info, int count, int i, int j)
{
	if (info->map.map[i][j] == '2')
	{
		info->sprite[count].x = j + 0.5f;
		info->sprite[count].y = i + 0.5f;
		info->sprite[count].num = 4;
		count++;
	}
	else if (info->map.map[i][j] == '3')
	{
		info->sprite[count].x = j + 0.5f;
		info->sprite[count].y = i + 0.5f;
		info->sprite[count].num = 7;
		count++;
	}
	return (count);
}
