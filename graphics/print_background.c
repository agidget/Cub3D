/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:42:24 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:42:26 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_floor(t_data *data, int ceil)
{
	int	x;
	int	y;

	x = 0;
	y = WIN_Y;
	while (y > WIN_Y / 2)
	{
		while (x <= WIN_X)
		{
			my_mlx_pixel_put(&data->img, x, y, ceil);
			x++;
		}
		x = 0;
		y--;
		if (y % 5 == 0)
			ceil = make_color_darker(ceil);
	}
}

void	print_ceil(t_data *data, int ceil)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_Y / 2)
	{
		while (x <= WIN_X)
		{
			my_mlx_pixel_put(&data->img, x, y, ceil);
			x++;
		}
		x = 0;
		y++;
		if (y % 5 == 0)
			ceil = make_color_darker(ceil);
	}
}

int	make_color_darker(int color)
{
	int		r;
	int		g;
	int		b;
	float	dark;

	dark = 0.97;
	r = color >> 16 & 0xFF;
	g = color >> 8 & 0xFF;
	b = color & 0xFF;
	r *= dark;
	g *= dark;
	b *= dark;
	return (r << 16 | g << 8 | b);
}

int	find_color(t_data *data, int height)
{
	int	color;
	int	dark;

	dark = (WIN_Y - height) / 10;
	color = (*(int *)(data->tex->addr + (4 * data->tex->width
					* (int)(roundf(data->tex->y))) + (4 * (int)data->tex->x)));
	while (dark > 0)
	{
		color = make_color_darker(color);
		dark--;
	}
	return (color);
}

void	print_background(t_data *data)
{
	print_ceil(data, data->ceil);
	print_floor(data, data->floor);
}
