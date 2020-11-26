/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:29:04 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:29:07 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			is_valid_wall(t_map *map, size_t i, size_t j, size_t len)
{
	if (i == map->map_height - 1 || map->map[i + 1][j] == ' ')
		return (-1);
	if (i == 0 || map->map[i - 1][j] == ' ')
		return (-1);
	if (j == len - 1 || map->map[i][j + 1] == ' ')
		return (-1);
	if (j == 0 || map->map[i][j - 1] == ' ')
		return (-1);
	return (0);
}

int			dir_uni(char c, int *count)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		(*count)++;
	if (*count > 1)
		return (1);
	return (0);
}

int			is_invalid_char(t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			if (!(map->map[i][j] == '1' || map->map[i][j] == '0' ||
			map->map[i][j] == ' ' || map->map[i][j] == '2' ||
			map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
			map->map[i][j] == 'E' || map->map[i][j] == 'W'))
				return (1);
		}
	}
	return (0);
}

int			map_check(t_info *info)
{
	size_t	i;
	size_t	j;
	size_t	len;
	int		count;

	i = -1;
	count = 0;
	if (is_invalid_char(&info->map))
		return (1);
	while (++i < info->map.map_height)
	{
		j = -1;
		len = ft_strlen(info->map.map[i]);
		while (++j < len)
		{
			if (info->map.map[i][j] != '1' && info->map.map[i][j] != ' ')
			{
				if (is_valid_wall(&info->map, i, j, len) ||
					dir_uni(info->map.map[i][j], &count))
					return (1);
			}
		}
	}
	return (count == 0 ? 1 : 0);
}

int			is_valid_map_file(char *str)
{
	int		len;
	int		result;

	len = ft_strlen(str);
	result = ft_strncmp(str + len - 4, ".cub", 4);
	return (result);
}
