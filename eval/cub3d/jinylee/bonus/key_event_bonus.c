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

#include "cub3d_bonus.h"

void		forward_back(t_game *info, char **map, double speed)
{
	if (map[(int)(info->y)][(int)(info->x + info->dir_x * speed)] != '1' &&
	map[(int)(info->y)][(int)(info->x + info->dir_x * speed)] != '3')
		info->x += info->dir_x * speed;
	if (map[(int)(info->y)][(int)(info->x + info->dir_x * speed)] == '2')
	{
		map[(int)(info->y)][(int)(info->x + info->dir_x * speed)] = '0';
		del_s(info, (int)(info->y), (int)(info->x + info->dir_x * speed));
		system("afplay -v 0.30 music/smile.mp3 &");
		info->hp -= 30;
	}
	if (map[(int)(info->y + info->dir_y * speed)][(int)(info->x)] != '1' &&
	map[(int)(info->y + info->dir_y * speed)][(int)(info->x)] != '3')
		info->y += info->dir_y * speed;
	if (map[(int)(info->y + info->dir_y * speed)][(int)(info->x)] == '2')
	{
		map[(int)(info->y + info->dir_y * speed)][(int)(info->x)] = '0';
		del_s(info, (int)(info->y + info->dir_y * speed), (int)(info->x));
		system("afplay -v 0.30 music/smile.mp3 &");
		info->hp -= 30;
	}
}

void		left_right(t_game *info, char **map, double speed)
{
	if (map[(int)(info->y)][(int)(info->x - info->dir_y * speed)] != '1' &&
	map[(int)(info->y)][(int)(info->x - info->dir_y * speed)] != '3')
		info->x -= info->dir_y * speed;
	if (map[(int)(info->y + info->dir_x * speed)][(int)(info->x)] != '1' &&
	map[(int)(info->y + info->dir_x * speed)][(int)(info->x)] != '3')
	{
		info->y += info->dir_x * speed;
		system("afplay -v 0.30 music/walking.mp3 &");
	}
}

void		myturn(t_game *info, double angle)
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

int			my_mouse(int x, int y, t_game *s)
{
	static int a;

	(void)y;
	if (s->mouse == x)
	{
		if (a > 0)
			myturn(s, s->rot_speed / 2);
		else
			myturn(s, -s->rot_speed / 2);
	}
	else if (s->mouse > x)
	{
		myturn(s, s->rot_speed / 2);
		a = 1;
	}
	else
	{
		myturn(s, -s->rot_speed / 2);
		a = -1;
	}
	s->mouse = x;
	return (0);
}

int			keypress(int key, t_game *info)
{
	char	**map;

	map = info->map.map;
	if (key == K_W)
	{
		forward_back(info, map, info->move_speed);
		system("afplay -v 0.30 music/walking.mp3 &");
	}
	if (key == K_S)
	{
		forward_back(info, map, -info->move_speed);
		system("afplay -v 0.30 music/walking.mp3 &");
	}
	if (key == K_A)
		left_right(info, map, info->move_speed);
	if (key == K_D)
		left_right(info, map, -info->move_speed);
	if (key == K_AR_L)
		myturn(info, info->rot_speed);
	if (key == K_AR_R)
		myturn(info, -info->rot_speed);
	if (key == K_ESC)
		free_out(info);
	return (0);
}
