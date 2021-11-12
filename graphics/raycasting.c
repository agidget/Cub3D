/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:42:31 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:42:33 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	cast_one_ray(t_data *data, int start_dir)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	x = data->player.x;
	y = roundf(data->player.y);
	while (1)
	{
		if ((int)x % SIZE == 0 || (int)y % SIZE == 0)
		{
			if (find_walls(data->map, x, y) == 1)
				break ;
		}
		x += cos(data->player.dir * PI / 180.0);
		y += sin(data->player.dir * PI / 180.0);
		i++;
	}
	i *= cos((start_dir - data->player.dir) * PI / 180.0);
	prepare_to_print(data, x, y, i);
	print_3d(data, i);
	mlx_destroy_image(data->win.mlx, data->tex->img);
}

float	find_stop(t_data *data)
{
	float	stop;
	float	temp;

	temp = data->player.dir;
	if (FOV / 2 > data->player.dir)
	{
		stop = data->player.dir + (FOV / 2);
		if (stop > 360)
			stop = stop - 360;
		data->player.dir = 360 - ((FOV / 2) - data->player.dir);
	}
	else
	{
		data->player.dir = data->player.dir - (FOV / 2);
		stop = temp + (FOV / 2);
		if (stop > 360)
			stop = stop - 360;
	}
	return (stop);
}

void	raycasting(t_data *data)
{
	float	temp;
	float	stop;
	int		i;

	i = 0;
	temp = data->player.dir;
	stop = find_stop(data);
	print_background(data);
	while (i < NUM_RAYS)
	{
		cast_one_ray(data, temp);
		data->player.dir += 0.50;
		if (data->player.dir > 360 && stop != 360)
			data->player.dir = 0;
		i++;
	}
	data->player.dir = temp;
}
