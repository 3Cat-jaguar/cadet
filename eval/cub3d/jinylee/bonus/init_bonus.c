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

#include "cub3d_bonus.h"

void	player_d(t_game *info, char direction)
{
	if (direction == 'N')
		myturn(info, M_PI / 2);
	else if (direction == 'S')
		myturn(info, -M_PI / 2);
	else if (direction == 'E')
		myturn(info, 0);
	else if (direction == 'W')
		myturn(info, M_PI);
}

int		player_p(t_game *info)
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
				player_d(info, info->map.map[i][j]);
				info->map.map[i][j] = '0';
				return (0);
			}
			j--;
		}
		i++;
	}
	return (0);
}

int		init_game(t_game *info)
{
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
	info->hp = 130;
	player_p(info);
	info->move_speed = 0.22;
	info->rot_speed = 0.05;
	if (!(info->z_buf = (double *)malloc(sizeof(double) * info->map.w)))
		return (1);
	if (!(info->r_dist = (double *)malloc(sizeof(double) * info->map.w)))
		return (1);
	make_tables(info);
	info->sprite_count = cnt_sprite(info);
	sprite_create(info);
	coo_sprite(info);
	return (0);
}

void	init_pic(t_cub *map)
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
