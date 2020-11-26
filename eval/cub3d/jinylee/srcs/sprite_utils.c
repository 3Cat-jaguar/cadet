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

#include "cub3d.h"

int				create_sprite(t_info *info)
{
	int			i;

	i = 0;
	if (!(info->sprite =
		(t_sprite *)malloc(sizeof(t_sprite) * info->sprite_count)))
		return (-1);
	while (i < info->sprite_count)
	{
		info->sprite[i].dist = 0;
		i++;
	}
	return (0);
}

void			sprite_coordinate(t_info *info)
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
			if (info->map.map[i][j] == '2')
			{
				info->sprite[count].x = j + 0.5f;
				info->sprite[count].y = i + 0.5f;
				count++;
			}
			j--;
		}
		i++;
	}
}

int				count_sprite(t_info *info)
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
			if (info->map.map[i][j] == '2')
				count++;
			j--;
		}
		i++;
	}
	return (count);
}

void			bubble_sorting(t_info *info)
{
	int			i;
	int			j;
	t_sprite	tmp;

	j = 0;
	while (j + 1 < info->sprite_count)
	{
		i = 0;
		while (i + 1 < info->sprite_count - j)
		{
			if (info->sprite[i].dist < info->sprite[i + 1].dist)
			{
				tmp = info->sprite[i];
				info->sprite[i] = info->sprite[i + 1];
				info->sprite[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

void			sprite_dist(t_info *info)
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
