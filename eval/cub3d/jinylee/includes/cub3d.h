/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:46:57 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/26 03:01:20 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "key.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define TEX_COUNT				5
# define TEXW					64
# define TEXH					64

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			num;
	int			order;
	double		dist;
	double		trans_x;
	double		trans_y;
	int			screen_x;
	int			sprite_w;
	int			sprite_h;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
}				t_sprite;

typedef struct	s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			tex_num;
}				t_ray;

typedef struct	s_map
{
	int			w;
	int			h;
	int			c;
	int			f;
	int			is_nl;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*path_s;
	char		*color_f;
	char		*color_c;
	t_list		*map_lst;
	char		**map;
	size_t		map_width;
	size_t		map_height;
}				t_map;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_w;
	int			img_h;
}				t_img;

typedef struct	s_info
{
	char		direction;
	int			mouse;
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	double		move_speed;
	double		rot_speed;
	int			*tex[TEX_COUNT];
	double		*z_buf;
	int			**buf;
	int			sprite_count;
	double		*r_dist;
	int			hp;
	t_ray		ray;
	t_map		map;
	t_img		img[TEX_COUNT];
	t_img		screen;
	t_sprite	*sprite;
}				t_info;

int				ft_arrlen(char **arr);
void			free_arr(char **arr);
int				**create_buf(int w, int h);
void			init_buf(t_info *info);
void			free_buf(int **buf, int i);
int				*load_image(t_info *info, char *path, t_img *img);

void			destroy_image(t_info *info);
void			sky_ground(t_info *info, int width, int height);
void			draw(t_info *info, int is_save);
void			load_texture(t_info *info, t_map *map);

int				path_check(char *path);
int				error_check(t_map *map);

void			free_map(t_map *map);
int				free_exit(t_info *info);
void			free_info(t_info *info);

void			player_dir(t_info *info, char direction);
int				player_pos(t_info *info);
int				init_info(t_info *info);
void			init_map(t_map *map);

int				key_press(int key, t_info *info);
void			rotate(t_info *info, double angle);
int				ft_mouse(int x, int y, t_info *s);

int				exit_error(t_info *info, int code, char const *str);
int				main_loop(t_info *info);
int				main_mlx(t_info *info);

int				is_valid_wall(t_map *map, size_t i, size_t j, size_t len);
int				is_valid_map_file(char *str);
int				is_invalid_char(t_map *map);
int				map_check(t_info *info);

int				map_check_null(t_map *map);
void			input_map_lst(t_map *map, char *line);
void			del(void *content);
int				make_map(t_map *map);

void			ray_casting(t_info *info);

int				input_identifier(t_map *map, char **arr);
int				map_parsing(t_info *info, char *path);
int				split_arr(t_info *info, char *line);

void			sprite_buf(t_info *info, int stripe, int i, int y);
void			transform_sprite(t_info *info, int i);
void			draw_sprite(t_info *info, t_sprite *sprite, int i);
void			init_sprite(t_info *info, t_sprite *sprite, int i);
void			sprite(t_info *info);

int				create_sprite(t_info *info);
void			sprite_coordinate(t_info *info);
int				count_sprite(t_info *info);
void			bubble_sorting(t_info *info);
void			sprite_dist(t_info *info);

void			init_ray(t_ray *ray, t_info *info, int x);
int				decide_dir(char direction);
double			cal_wall(t_ray *ray, t_info *info);
int				cal_tex_x(t_ray *ray, t_info *info);
void			fill_buf(t_img *img, t_ray *ray, t_info *info, int x);
#endif
