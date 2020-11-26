/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:30:07 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:30:09 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "save.h"

int			exit_error(t_info *info, int code, char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	exit(code);
	destroy_image(info);
	free_info(info);
	return (code);
}

int			main_loop(t_info *info)
{
	sky_ground(info, info->map.w, info->map.h);
	ray_casting(info);
	sprite(info);
	draw(info, 0);
	return (0);
}

int			main_mlx(t_info *info)
{
	info->mlx = mlx_init();
	if (init_info(info))
		return (1);
	info->win = mlx_new_window(info->mlx, info->map.w, info->map.h, "cub3D");
	if (!(info->buf = create_buf(info->map.w, info->map.h)))
		return (1);
	init_buf(info);
	load_texture(info, &info->map);
	info->screen.img = mlx_new_image(info->mlx, info->map.w, info->map.h);
	info->screen.data = (int *)mlx_get_data_addr(info->screen.img,
		&info->screen.bpp, &info->screen.size_l, &info->screen.endian);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, key_press, info);
	mlx_hook(info->win, 6, 0, ft_mouse, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, free_exit, info);
	mlx_loop_hook(info->mlx, main_loop, info);
	mlx_loop(info->mlx);
	return (0);
}

int			save_img(t_info *info)
{
	info->mlx = mlx_init();
	if (init_info(info))
		return (1);
	if (!(info->buf = create_buf(info->map.w, info->map.h)))
		return (1);
	init_buf(info);
	load_texture(info, &info->map);
	info->screen.img = mlx_new_image(info->mlx, info->map.w, info->map.h);
	info->screen.data = (int *)mlx_get_data_addr(info->screen.img,
		&info->screen.bpp, &info->screen.size_l, &info->screen.endian);
	sky_ground(info, info->map.w, info->map.h);
	ray_casting(info);
	sprite(info);
	draw(info, 1);
	create_bmp(info);
	return (0);
}

int			main(int argc, char *argv[])
{
	t_info	info;

	if (!(argc == 2 || (argc == 3 && (!ft_strncmp(argv[2], "--save", 6) &&
	ft_strlen(argv[2]) == 6))))
		return (exit_error(&info, 1, "ERROR\nargument error\n"));
	if (is_valid_map_file(argv[1]) || map_parsing(&info, argv[1]))
		return (exit_error(&info, 1, "ERROR\nparsing map error\n"));
	if (argc == 2)
	{
		if (main_mlx(&info))
			return (exit_error(&info, 1, "ERROR\nmalloc error\n"));
	}
	if (argc == 3)
		if (save_img(&info))
			return (exit_error(&info, 1, "ERROR\nsave error\n"));
	return (0);
}
