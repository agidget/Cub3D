/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:42:11 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:42:13 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	close_win(t_data **data)
{
	mlx_clear_window ((*data)->win.mlx, (*data)->win.win);
	mlx_destroy_window ((*data)->win.mlx, (*data)->win.win);
	free_data(*data);
	exit(0);
}

int	key_hook(int keycode, t_data **data)
{
	if (keycode == ESC)
		close_win (data);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
	{
		mlx_clear_window ((*data)->win.mlx, (*data)->win.win);
		player_movement(*data, keycode);
		raycasting(*data);
	}
	if (keycode == L_ARR || keycode == R_ARR)
		turn_around(keycode, data);
	mlx_put_image_to_window((*data)->win.mlx,
		(*data)->win.win, (*data)->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	main_parser(argv, &data);
	data->win.mlx = mlx_init();
	data->win.win = mlx_new_window(data->win.mlx, 725, 481, "cub3D");
	data->img.img = mlx_new_image(data->win.mlx, 725, 481);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	raycasting(data);
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img.img, 0, 0);
	mlx_hook(data->win.win, 02, (1L << 0), &key_hook, &data);
	mlx_hook(data->win.win, 17, 0, &close_win, &data);
	mlx_loop(data->win.mlx);
	return (0);
}
