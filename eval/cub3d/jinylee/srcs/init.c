/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:29:59 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:30:01 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_dir(t_info *info, char direction)
{
	if (direction == 'N')
		rotate(info, M_PI / 2);
	else if (direction == 'S')
		rotate(info, -M_PI / 2);
	else if (direction == 'E')
		rotate(info, 0);
	else if (direction == 'W')
		rotate(info, M_PI);
}

int		player_pos(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)info->map.map_height)
	{
		j = ft_strlen(info->map.map[i]) - 1;
		while (j > 0)
		{
			if (info->map.map[i][j] == 'N' || info->map.map[i][j] == 'S' ||
				info->map.map[i][j] == 'E' || info->map.map[i][j] == 'W')
			{
				info->x = j + 0.1;
				info->y = i + 0.1;
				player_dir(info, info->map.map[i][j]);
				info->map.map[i][j] = '0';
				return (0);
			}
			j--;
		}
		i++;
	}
	return (0);
}

int		init_info(t_info *info)
{
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
	player_pos(info);
	info->move_speed = 0.33;
	info->rot_speed = 0.05;
	if (!(info->z_buf = (double *)malloc(sizeof(double) * info->map.w)))
		return (1);
	info->sprite_count = count_sprite(info);
	create_sprite(info);
	sprite_coordinate(info);
	return (0);
}

void	init_map(t_map *map)
{
	map->path_no = NULL;
	map->path_so = NULL;
	map->path_we = NULL;
	map->path_ea = NULL;
	map->path_s = NULL;
	map->color_c = NULL;
	map->color_f = NULL;
	map->h = 0;
	map->w = 0;
	map->is_nl = 0;
	map->map_lst = 0;
	map->map_width = 0;
	map->map_height = 0;
}
