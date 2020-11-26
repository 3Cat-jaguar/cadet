/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:29:13 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:29:15 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_algorithm(t_ray *ray, t_info *info)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (info->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - info->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (info->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - info->y) * ray->delta_dist_y;
	}
}

void	is_hit(t_ray *ray, char **map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	sol_fisheye(t_ray *ray, t_info *info)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist =
			(ray->map_x - info->x + (1 - ray->step_x) / 2) / ray->dir_x;
		if (ray->dir_x > 0)
			info->direction = 'W';
		else
			info->direction = 'E';
	}
	else
	{
		ray->perp_wall_dist =
			(ray->map_y - info->y + (1 - ray->step_y) / 2) / ray->dir_y;
		if (ray->dir_y < 0)
			info->direction = 'N';
		else
			info->direction = 'S';
	}
}

void	vertical_line(t_ray *ray, t_map *map)
{
	ray->line_h = (int)(map->h / ray->perp_wall_dist);
	ray->draw_start = -ray->line_h / 2 + map->h / 2;
	ray->draw_end = ray->line_h / 2 + map->h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= map->h)
		ray->draw_end = map->h - 1;
}

void	ray_casting(t_info *info)
{
	int	ray_id;

	ray_id = 0;
	while (ray_id < info->map.w)
	{
		init_ray(&info->ray, info, ray_id);
		dda_algorithm(&info->ray, info);
		is_hit(&info->ray, info->map.map);
		sol_fisheye(&info->ray, info);
		vertical_line(&info->ray, &info->map);
		fill_buf(info->img, &info->ray, info, ray_id);
		info->z_buf[ray_id] = info->ray.perp_wall_dist;
		ray_id++;
	}
}
