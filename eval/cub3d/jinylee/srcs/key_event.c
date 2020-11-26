/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:28:53 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:28:54 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		forward_back(t_info *info, char **map, double speed)
{
	if (map[(int)(info->y)][(int)(info->x + info->dir_x * speed)] != '1' &&
	map[(int)(info->y)][(int)(info->x + info->dir_x * speed)] != '2')
	{
		info->x += info->dir_x * speed;
	}
	if (map[(int)(info->y + info->dir_y * speed)][(int)(info->x)] != '1' &&
	map[(int)(info->y + info->dir_y * speed)][(int)(info->x)] != '2')
	{
		info->y += info->dir_y * speed;
	}
}

void		left_right(t_info *info, char **map, double speed)
{
	if (map[(int)(info->y)][(int)(info->x - info->dir_y * speed)] != '1' &&
	map[(int)(info->y)][(int)(info->x - info->dir_y * speed)] != '2')
	{
		info->x -= info->dir_y * speed;
	}
	if (map[(int)(info->y + info->dir_x * speed)][(int)(info->x)] != '1' &&
	map[(int)(info->y + info->dir_x * speed)][(int)(info->x)] != '2')
	{
		info->y += info->dir_x * speed;
	}
}

void		rotate(t_info *info, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(angle) - info->dir_y * sin(angle);
	info->dir_y = old_dir_x * sin(angle) + info->dir_y * cos(angle);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(angle) - info->plane_y * sin(angle);
	info->plane_y = old_plane_x * sin(angle) + info->plane_y * cos(angle);
}

int			ft_mouse(int x, int y, t_info *s)
{
	static int a;

	(void)y;
	if (s->mouse == x)
	{
		if (a > 0)
			rotate(s, s->rot_speed / 2);
		else
			rotate(s, -s->rot_speed / 2);
	}
	else if (s->mouse > x)
	{
		rotate(s, s->rot_speed / 2);
		a = 1;
	}
	else
	{
		rotate(s, -s->rot_speed / 2);
		a = -1;
	}
	s->mouse = x;
	return (0);
}

int			key_press(int key, t_info *info)
{
	char	**map;

	map = info->map.map;
	if (key == K_W)
		forward_back(info, map, info->move_speed);
	if (key == K_S)
		forward_back(info, map, -info->move_speed);
	if (key == K_A)
		left_right(info, map, info->move_speed);
	if (key == K_D)
		left_right(info, map, -info->move_speed);
	if (key == K_AR_L)
		rotate(info, info->rot_speed);
	if (key == K_AR_R)
		rotate(info, -info->rot_speed);
	if (key == K_ESC)
		free_exit(info);
	return (0);
}
