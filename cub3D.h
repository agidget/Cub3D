/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:13:26 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:13:39 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include "Libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>

typedef struct s_win {
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	int		x;
	int		y;
	float	dir;
}	t_player;

typedef struct s_walls
{
	int	prev;
	int	new;
}	t_walls;

typedef struct s_tex
{
	char	*addr;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	float	x;
	int		offset;
	float	y;
}	t_tex;

typedef struct s_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor;
	int			ceil;
	char		**map;
	int			file_size;
	int			map_size;
	t_player	player;
	t_win		win;
	t_img		img;
	t_walls		walls;
	t_tex		*tex;
}	t_data;

int		find_high(int d);
int		find_real_height(int d);
void	find_texture(t_data *data, int x, int y);
void	main_parser(char **argv, t_data	**data);
void	print_3d(t_data *data, int d);
void	raycasting(t_data *data);
void	prepare_to_print(t_data *data, int x_in_wall,
			int y_in_wall, int height);
void	print_background(t_data *data);
void	turn_around(int keycode, t_data **data);
void	raycasting(t_data *data);
int		find_color(t_data *data, int height);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	print_square(int x, int y, t_img img, int color);
void	print_ray(t_data *data, int start_dir);
void	print_rays(t_data *data);
void	print_little_square(int x, int y, t_img img, int color);
int		make_color_darker(int color);
void	print_borders(t_img img);
int		find_walls(char **map, int x, int y);
int		array_size(char **map);
int		change_position(t_data *data, int *x, int *y, int keycode);
void	player_movement(t_data *data, int keycode);
void	file_error(t_list *list, t_data *data);
void	check_first_ch(t_list *list, t_data *data);
void	check_list(t_list *list, t_data *data);
void	if_error(void);
t_list	*read_file(char *arg);
void	free_list(t_list *list);
int		create_rgb(int r, int g, int b);
void	malloc_error(void *ptr);
t_data	*init_data(void);
void	free_data(t_data *data);
char	*texture_link(char *str, int *i);
void	no_side(t_list *list, t_data *data, char *str, int *i);
void	so_side(t_list *list, t_data *data, char *str, int *i);
void	we_side(t_list *list, t_data *data, char *str, int *i);
void	ea_side(t_list *list, t_data *data, char *str, int *i);
void	fill_data(t_list *list, t_data *data, char *str, int *i);
void	check_list(t_list *list, t_data *data);
void	floor_color(t_list *list, t_data *data, char *str, int *i);
void	ceilling_color(t_list *list, t_data *data, char *str, int *i);
void	for_free(char **new);
void	check_borders(t_list *list, t_data *data);
void	check_after_link(t_list *list, t_data *data, char *str, int *i);
void	check_map(t_list *list, t_data *data);
int		arr_size(char **arr);
void	error_color(char **arr, t_list *list, t_data *data);
int		ft_atoi_mod(char *str, char **arr, t_list *list, t_data *data);
void	avail_chars_map(t_list *list, t_data *data, int a, int b);
void	map_error(t_list *list, t_data *data);
void	if_space_error(t_list *list, t_data *data, int a, int b);
void	check_if_space_correct(t_list *list, t_data *data, int i, int j);
void	if_space_in_map(t_list *list, t_data *data, int i, int j);
void	general_map_check(t_list *list, t_data *data);
void	check_borders_top_bottom(t_list *list, t_data *data);
void	check_borders_left_right(t_list *list, t_data *data);
void	check_borders(t_list *list, t_data *data);
void	check_map(t_list *list, t_data *data);
void	check_all_file(t_list *list, t_data *data);
int		ft_strcmp(char *s1, char *s2);
void	link_error(t_list *list, t_data *data);
void	check_textures(t_list *list, t_data *data);
int		find_dir(int dir);

# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT		2
# define ESC		53
# define L_ARR		123
# define R_ARR		124
# define WIN_X		728
# define WIN_Y		480
# define PI			3.14159265
# define SIZE		40
# define SPEED		10
# define FOV		90
# define NUM_RAYS	181
#endif
