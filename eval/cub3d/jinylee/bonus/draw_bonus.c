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

#include "cub3d_bonus.h"

void	load_tex(t_game *info, t_cub *map)
{
	info->tex[0] = loadimage(info, map->path_no, &info->img[0]);
	info->tex[1] = loadimage(info, map->path_so, &info->img[1]);
	info->tex[2] = loadimage(info, map->path_ea, &info->img[2]);
	info->tex[3] = loadimage(info, map->path_we, &info->img[3]);
	info->tex[4] = loadimage(info, map->path_s, &info->img[4]);
	info->tex[5] = loadimage(info, map->path_f, &info->img[5]);
	info->tex[6] = loadimage(info, map->path_c, &info->img[6]);
	info->tex[7] = loadimage(info, map->path_ss, &info->img[7]);
	info->tex[8] = loadimage(info, "./textures/lifebar.xpm", &info->img[8]);
}

void	destroy_img(t_game *info)
{
	int		i;

	i = -1;
	while (++i < TEX_C)
		mlx_destroy_image(info->mlx, info->img[i].img);
}

void	ft_draw(t_game *info, int is_save)
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
