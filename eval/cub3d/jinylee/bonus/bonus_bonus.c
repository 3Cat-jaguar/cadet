/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@stdent.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:53:04 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/25 23:15:48 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_bonus(t_cub *map, char **arr)
{
	if (!(ft_strncmp(arr[0], "SS", 3)) && (ft_arrlen(arr) == 2))
		map->path_ss = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "FF", 3)) && (ft_arrlen(arr) == 2))
		map->path_f = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "CC", 2)) && (ft_arrlen(arr) == 2))
		map->path_c = ft_strndupup(arr[1]);
	else
		return (1);
	return (0);
}

int		shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
			+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
			+ ((int)((0x0000FF & color) / divide)));
}

int		distance_shade(int color, double distance)
{
	return (shade_color(color, distance / 1.5));
}

void	set_sf(t_game *info, t_fs *sf, int y)
{
	int h;
	int w;

	h = info->map.h;
	w = info->map.w;
	sf->raydirx0 = info->dir_x - info->plane_x;
	sf->raydiry0 = info->dir_y - info->plane_y;
	sf->raydirx1 = info->dir_x + info->plane_x;
	sf->raydiry1 = info->dir_y + info->plane_y;
	sf->p = y - h / 2;
	sf->posz = 0.5 * y;
	sf->rowdistance = sf->posz / sf->p;
	sf->floorstepx = sf->rowdistance * (sf->raydirx1 - sf->raydirx0) / h;
	sf->floorstepy = sf->rowdistance * (sf->raydiry1 - sf->raydiry0) / w;
	sf->floorx = info->x + sf->rowdistance * sf->raydirx0;
	sf->floory = info->y + sf->rowdistance * sf->raydiry0;
}

void	draw_skyground(t_game *info, int w, int h)
{
	int		y;
	int		x;
	t_fs	sf;
	int		color;

	y = -1;
	while (++y < h)
	{
		set_sf(info, &sf, y);
		x = -1;
		while (++x < w)
		{
			sf.cellx = (int)(sf.floorx);
			sf.celly = (int)(sf.floory);
			sf.tx = (int)(64 * (sf.floorx - sf.cellx)) & (64 - 1);
			sf.ty = (int)(64 * (sf.floory - sf.celly)) & (64 - 1);
			sf.floorx += sf.floorstepx;
			sf.floory += sf.floorstepy;
			color = info->tex[5][64 * sf.ty + sf.tx];
			info->buf[y][x] = distance_shade(color, info->r_dist[y]);
			color = info->tex[6][64 * sf.ty + sf.tx];
			info->buf[h - y - 1][x] = distance_shade(color, info->r_dist[y]);
		}
	}
}
