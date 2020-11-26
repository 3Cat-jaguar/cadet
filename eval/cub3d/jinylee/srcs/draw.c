/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:28:13 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:28:22 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_info *info, t_map *map)
{
	info->tex[0] = load_image(info, map->path_no, &info->img[0]);
	info->tex[1] = load_image(info, map->path_so, &info->img[1]);
	info->tex[2] = load_image(info, map->path_ea, &info->img[2]);
	info->tex[3] = load_image(info, map->path_we, &info->img[3]);
	info->tex[4] = load_image(info, map->path_s, &info->img[4]);
}

void	destroy_image(t_info *info)
{
	int		i;

	i = -1;
	while (++i < TEX_COUNT)
		mlx_destroy_image(info->mlx, info->img[i].img);
}

void	sky_ground(t_info *info, int width, int height)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (i < height / 2)
				info->buf[i][j] = info->map.f;
			else
				info->buf[i][j] = info->map.c;
		}
	}
}

void	draw(t_info *info, int is_save)
{
	int x;
	int y;

	y = -1;
	while (++y < info->map.h)
	{
		x = -1;
		while (++x < info->map.w)
			info->screen.data[y * info->map.w + x] = info->buf[y][x];
	}
	if (!is_save)
		mlx_put_image_to_window(info->mlx, info->win, info->screen.img, 0, 0);
}
