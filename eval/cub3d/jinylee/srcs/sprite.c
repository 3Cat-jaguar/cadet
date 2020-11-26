/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:30:32 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:30:34 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sprite_buf(t_info *info, int stripe, int i, int y)
{
	int		d;
	int		tex_x;
	int		tex_y;

	tex_x = (int)(256 * (stripe - (-info->sprite[i].sprite_w /
	2 + info->sprite[i].screen_x)) * TEXW / info->sprite[i].sprite_w) / 256;
	if (info->sprite[i].trans_y > 0 && stripe > 0 && stripe < info->map.w
		&& info->sprite[i].trans_y < info->z_buf[stripe])
		while (y < info->sprite[i].end_y)
		{
			d = (y) * 256 - info->map.h * 128 + info->sprite[i].sprite_h * 128;
			tex_y = ((d * TEXH) / info->sprite[i].sprite_h) / 256;
			if ((info->tex[4][TEXW * tex_y + tex_x] & 0x00FFFFFF) != 0)
				info->buf[y][stripe] = info->tex[4][TEXW * tex_y + tex_x];
			y++;
		}
}

void		transform_sprite(t_info *info, int i)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = info->sprite[info->sprite[i].order].x - info->x;
	sprite_y = info->sprite[info->sprite[i].order].y - info->y;
	inv_det = 1.0 / (info->plane_x * info->dir_y - info->dir_x * info->plane_y);
	info->sprite[i].trans_x = inv_det * (info->dir_y *
		sprite_x - info->dir_x * sprite_y);
	info->sprite[i].trans_y = inv_det *
		(-info->plane_y * sprite_x + info->plane_x * sprite_y);
	info->sprite[i].screen_x = (int)((info->map.w / 2) *
		(1 + info->sprite[i].trans_x / info->sprite[i].trans_y));
}

void		draw_sprite(t_info *info, t_sprite *sprite, int i)
{
	int		y;
	int		stripe;

	stripe = sprite[i].start_x;
	while (stripe < sprite[i].end_x)
	{
		y = sprite[i].start_y;
		sprite_buf(info, stripe, i, y);
		stripe++;
	}
}

void		init_sprite(t_info *info, t_sprite *sprite, int i)
{
	sprite[i].sprite_h = abs((int)(info->map.h / (sprite[i].trans_y)));
	sprite[i].start_y = -sprite[i].sprite_h / 2 + info->map.h / 2;
	if (sprite[i].start_y < 0)
		sprite[i].start_y = 0;
	sprite[i].end_y = sprite[i].sprite_h / 2 + info->map.h / 2;
	if (sprite[i].end_y >= info->map.h)
		sprite[i].end_y = info->map.h - 1;
	sprite[i].sprite_w = abs((int)(info->map.h / (sprite[i].trans_y)));
	sprite[i].start_x = -sprite[i].sprite_w / 2 + sprite[i].screen_x;
	if (sprite[i].start_x < 0)
		sprite[i].start_x = 0;
	sprite[i].end_x = sprite[i].sprite_w / 2 + sprite[i].screen_x;
	if (sprite[i].end_x >= info->map.w)
		sprite[i].end_x = info->map.w - 1;
}

void		sprite(t_info *info)
{
	int		i;

	i = 0;
	sprite_dist(info);
	bubble_sorting(info);
	while (i < info->sprite_count)
	{
		transform_sprite(info, i);
		init_sprite(info, info->sprite, info->sprite[i].order);
		draw_sprite(info, info->sprite, info->sprite[i].order);
		i++;
	}
}
