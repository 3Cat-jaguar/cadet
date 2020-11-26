/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:29:32 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:29:34 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int				sprite_create(t_game *info)
{
	int			i;

	i = 0;
	if (!(info->sprite =
		(t_sprit *)malloc(sizeof(t_sprit) * info->sprite_count)))
		return (-1);
	while (i < info->sprite_count)
	{
		info->sprite[i].dist = 0;
		info->sprite[i].num = 4;
		info->sprite[i].del = 0;
		i++;
	}
	return (0);
}

void			coo_sprite(t_game *info)
{
	int			i;
	int			j;
	int			count;

	i = -1;
	count = 0;
	while (++i < (int)info->map.map_height)
	{
		j = ft_strlen(info->map.map[i]) - 1;
		while (j > 0)
		{
			count = ft_cnt(info, count, i, j);
			j--;
		}
	}
}

int				cnt_sprite(t_game *info)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	count = 0;
	while (i < (int)info->map.map_height)
	{
		j = ft_strlen(info->map.map[i]) - 1;
		while (j > 0)
		{
			if (info->map.map[i][j] == '2' || info->map.map[i][j] == '3')
				count++;
			j--;
		}
		i++;
	}
	return (count);
}

void			ft_sorting(t_game *info)
{
	int			i;
	int			j;
	t_sprit		tmp;

	j = 0;
	while (j < info->sprite_count - 1)
	{
		i = j + 1;
		while (i < info->sprite_count)
		{
			if (info->sprite[i].dist > info->sprite[j].dist)
			{
				ft_swap(&tmp, &info->sprite[j]);
				ft_swap(&info->sprite[j], &info->sprite[i]);
				ft_swap(&info->sprite[i], &tmp);
			}
			i++;
		}
		j++;
	}
}

void			ft_distance(t_game *info)
{
	int			i;

	i = 0;
	while (i < info->sprite_count)
	{
		info->sprite[i].dist = ((info->x - info->sprite[i].x) *
		(info->x - info->sprite[i].x) + (info->y - info->sprite[i].y)
		* (info->y - info->sprite[i].y));
		info->sprite[i].order = i;
		i++;
	}
}
