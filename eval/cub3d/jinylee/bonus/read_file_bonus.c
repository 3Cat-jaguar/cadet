/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:30:21 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:30:24 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		limit_screen_size(t_cub *map)
{
	if (map->w > 1920)
		map->w = 1920;
	if (map->h > 1080)
		map->h = 1080;
	if (map->w < 200)
		map->w = 200;
	if (map->h < 200)
		map->h = 200;
}

int			path_input(t_cub *map, char **arr)
{
	if (!(ft_strncmp(arr[0], "NO", 3)) && (ft_arrlen(arr) == 2))
		map->path_no = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "SO", 3)) && (ft_arrlen(arr) == 2))
		map->path_so = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "WE", 3)) && (ft_arrlen(arr) == 2))
		map->path_we = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "EA", 3)) && (ft_arrlen(arr) == 2))
		map->path_ea = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "S", 2)) && (ft_arrlen(arr) == 2))
		map->path_s = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "R", 2)) && (ft_arrlen(arr) == 3))
	{
		map->w = ft_atoi(arr[1]);
		map->h = ft_atoi(arr[2]);
		limit_screen_size(map);
	}
	else if (!(ft_strncmp(arr[0], "F", 2)) && (ft_arrlen(arr) == 2))
		map->color_f = ft_strndupup(arr[1]);
	else if (!(ft_strncmp(arr[0], "C", 2)) && (ft_arrlen(arr) == 2))
		map->color_c = ft_strndupup(arr[1]);
	else if (ft_bonus(map, arr))
		return (1);
	return (0);
}

int			arr_split(t_game *info, char *line)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (path_input(&info->map, arr))
	{
		free(line);
		return (-1);
	}
	free_arr(arr);
	free(line);
	return (0);
}

int			read_mapfile(t_game *info, int fd)
{
	int		is_read;
	char	*line;

	while ((is_read = get_next_line(fd, &line)) >= 0)
	{
		if (!info->map.is_nl && !(ft_strncmp(line, "", 1)))
			free(line);
		else if (check_null(&info->map))
		{
			if (arr_split(info, line))
				return (1);
		}
		else
		{
			info->map.is_nl = 1;
			input_lst(&info->map, line);
			free(line);
		}
		if (!is_read)
			break ;
	}
	map_make(&info->map);
	return (0);
}

int			parsing_map(t_game *info, char *path)
{
	int		fd;

	init_pic(&info->map);
	if ((fd = open(path, O_RDONLY)) == -1 || read_mapfile(info, fd))
		return (-1);
	if (check_cub(info))
		return (-1);
	return (error_chk(&info->map));
}
