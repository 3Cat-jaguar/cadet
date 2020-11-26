/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:01:56 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/26 05:38:53 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_lifebar(t_game *s)
{
	unsigned int	color;
	int				i;
	int				j;

	i = 0;
	while (i < 72)
	{
		j = 0;
		while (j < 260)
		{
			color = s->tex[8][i / 4 * 65 + j / 4];
			if (color == 0xFF000000)
			{
				color = (s->buf[i + 20][j + 20] / (256 * 256) % 256) /
					2 * 256 * 256;
				color += (s->buf[i + 20][j + 20] / 256 % 256) / 2 * 256;
				color += (s->buf[i + 20][j + 20] % 256) / 2;
			}
			if (color < 0xFF000000)
				s->buf[i + 20][j + 20] = color;
			j++;
		}
		i++;
	}
}

void	ft_health(t_game *s)
{
	unsigned int	color;
	int				i;
	int				j;

	i = 0;
	while (i < 72)
	{
		j = 0;
		while (j < 260)
		{
			color = s->tex[8][(i / 4 + 18) * 65 + j / 4];
			if (color != 0xFF000000 && j - 56 < s->hp)
				s->buf[i + 20][j + 20] = color;
			j++;
		}
		i++;
	}
}

void	ft_minimap(t_game *s, size_t i, size_t j, int color)
{
	size_t	ii;
	size_t	jj;

	ii = 10 * i + 1;
	while (ii <= 10 * (i + 1))
	{
		jj = 10 * j + 1;
		while (jj <= 10 * (j + 1))
		{
			s->buf[ii + s->map.h * 3 / 5][jj + 20] = color;
			jj++;
		}
		ii++;
	}
}

void	add_img(t_game *s)
{
	size_t	i;
	size_t	j;

	ft_lifebar(s);
	ft_health(s);
	crossshot(s);
	i = -1;
	while (++i < s->map.map_height)
	{
		j = -1;
		while (++j < s->map.map_width)
		{
			if (s->map.map[i][j] == '1')
				ft_minimap(s, i, j, 0xFFFFFF);
			else if ((int)s->x == (int)j && (int)s->y == (int)i)
				ft_minimap(s, i, j, 0x00FF00);
			else if (s->map.map[i][j] == '0')
				ft_minimap(s, i, j, 0x222222);
			else if (s->map.map[i][j] == '3')
				ft_minimap(s, i, j, 0xFF0000);
			else if (s->map.map[i][j] == '2')
				ft_minimap(s, i, j, 0x0000FF);
		}
	}
}

void	del_s(t_game *s, int y, int x)
{
	int	i;

	i = 0;
	while (i < s->sprite_count)
	{
		if ((int)s->sprite[i].x == x && (int)s->sprite[i].y == y)
		{
			s->sprite[i].del = 1;
			break ;
		}
		i++;
	}
}
