/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcast_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:30:38 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:30:40 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ray_init(t_ra *ray, t_game *info, int ray_id)
{
	ray->camera_x = 2 * ray_id / (double)info->map.w - 1;
	ray->dir_x = info->plane_x * ray->camera_x + info->dir_x;
	ray->dir_y = info->plane_y * ray->camera_x + info->dir_y;
	ray->map_x = (int)info->x;
	ray->map_y = (int)info->y;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
}

int		find_dir(char dir)
{
	if (dir == 'N')
		return (0);
	else if (dir == 'W')
		return (1);
	else if (dir == 'E')
		return (2);
	else if (dir == 'S')
		return (3);
	return (-1);
}

double	wall_cal(t_ra *ray, t_game *info)
{
	double	wall_x;

	ray->tex_num = find_dir(info->direction);
	if (ray->side == 0)
		wall_x = info->y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = info->x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int		tex_x_cal(t_ra *ray, t_game *info)
{
	int		tex_x;
	int		tex_w;

	tex_w = info->img[0].img_w;
	tex_x = (int)(wall_cal(ray, info) * (double)tex_w);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_x = tex_w - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex_x = tex_w - tex_x - 1;
	return (tex_x);
}

void	input_but(t_pic *img, t_ra *ray, t_game *info, int x)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	tex_x = tex_x_cal(ray, info);
	step = 1.0 * img[0].img_h / ray->line_h;
	tex_pos = (ray->draw_start - info->map.h / 2 + ray->line_h / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (img[0].img_h - 1);
		tex_pos += step;
		info->buf[y][x] =
			distance_shade(info->tex[ray->tex_num][img[0].
			img_w * tex_y + tex_x], ray->perp_wall_dist);
		y++;
	}
}
