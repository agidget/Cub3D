/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:42:28 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:42:30 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_wall_with_tex(t_data *data, int x, int y, int d)
{
	int		color;
	float	temp;
	float	step;
	int		high;

	temp = data->tex->y;
	high = find_high(d);
	if (find_high(d) < find_real_height(d))
		step = (data->tex->height - data->tex->y * 2) / WIN_Y;
	else
		step = (float)data->tex->height / (float)high;
	while (roundf(data->tex->y) < data->tex->height && y < WIN_Y)
	{
		color = find_color(data, high);
		my_mlx_pixel_put(&data->img, x, y, color);
		y++;
		data->tex->y += step;
	}
	data->tex->y = temp;
}

void	print_3d(t_data *data, int d)
{
	int			width;
	int			high;
	static int	x = 0;
	int			y;

	high = find_high(d);
	y = WIN_Y / 2 - high / 2;
	width = WIN_X / NUM_RAYS;
	while (width > 0)
	{
		print_wall_with_tex(data, x, y, d);
		data->tex->x++;
		x += 1;
		high = find_high(d);
		y = WIN_Y / 2 - high / 2;
		width--;
	}
	width = WIN_X / NUM_RAYS;
	if (x == width * NUM_RAYS)
		x = 0;
}
