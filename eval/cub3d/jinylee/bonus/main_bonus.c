/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:30:07 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/26 01:44:48 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "save_bonus.h"

int			exit_game(t_game *info, int code, char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	exit(code);
	destroy_img(info);
	free_game(info);
	system("killall afplay");
	return (code);
}

int			ft_loop(t_game *info)
{
	draw_skyground(info, info->map.w, info->map.h);
	raycasting(info);
	ft_sprite(info);
	add_img(info);
	ft_draw(info, 0);
	return (0);
}

int			ft_mlx(t_game *info)
{
	info->mlx = mlx_init();
	if (init_game(info))
		return (1);
	info->win = mlx_new_window(info->mlx, info->map.w, info->map.h, "cub3D");
	if (!(info->buf = create_buf(info->map.w, info->map.h)))
		return (1);
	initbuf(info);
	load_tex(info, &info->map);
	info->screen.img = mlx_new_image(info->mlx, info->map.w, info->map.h);
	info->screen.data = (int *)mlx_get_data_addr(info->screen.img,
		&info->screen.bpp, &info->screen.size_l, &info->screen.endian);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, keypress, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, keypress, info);
	mlx_hook(info->win, 6, 0, my_mouse, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, free_out, info);
	mlx_loop_hook(info->mlx, ft_loop, info);
	mlx_loop(info->mlx);
	return (0);
}

int			save_img(t_game *info)
{
	info->mlx = mlx_init();
	if (init_game(info))
		return (1);
	if (!(info->buf = create_buf(info->map.w, info->map.h)))
		return (1);
	initbuf(info);
	load_tex(info, &info->map);
	info->screen.img = mlx_new_image(info->mlx, info->map.w, info->map.h);
	info->screen.data = (int *)mlx_get_data_addr(info->screen.img,
		&info->screen.bpp, &info->screen.size_l, &info->screen.endian);
	draw_skyground(info, info->map.w, info->map.h);
	raycasting(info);
	ft_sprite(info);
	ft_draw(info, 1);
	make_bmp(info);
	return (0);
}

int			main(int argc, char *argv[])
{
	t_game	info;

	if (!(argc == 2 || (argc == 3 && (!ft_strncmp(argv[2], "--save", 6) &&
	ft_strlen(argv[2]) == 6))))
		return (exit_game(&info, 1, "ERROR\nargument error\n"));
	if (check_cubfile(argv[1]) || parsing_map(&info, argv[1]))
		return (exit_game(&info, 1, "ERROR\nparsing map error\n"));
	if (argc == 2)
	{
		system("afplay -v 0.30 music/eyes.mp3 &");
		if (ft_mlx(&info))
			return (exit_game(&info, 1, "ERROR\nmalloc error\n"));
	}
	if (argc == 3)
		if (save_img(&info))
			return (exit_game(&info, 1, "ERROR\nsave error\n"));
	return (0);
}
