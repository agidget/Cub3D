/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:42:20 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:42:22 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	find_real_height(int d)
{
	int	height;

	if (d == 0)
	{
		height = WIN_Y;
		return (height);
	}
	else
		height = (NUM_RAYS / (2 * tan(45 * PI / 180.0)) * WIN_Y) / d;
	if (height % 2 != 0)
		height++;
	return (height);
}

int	find_high(int d)
{
	int	height;

	height = find_real_height(d);
	if (height > WIN_Y)
	{
		height = WIN_Y;
	}
	return (height);
}

void	prepare_to_print(t_data *data, int x_in_wall, int y_in_wall, int height)
{
	float	del;

	find_texture(data, x_in_wall, y_in_wall);
	del = (float)data->tex->width / (float)SIZE;
	if (x_in_wall % SIZE == 0)
		data->tex->offset = y_in_wall % SIZE;
	else
		data->tex->offset = x_in_wall % SIZE;
	data->tex->x = data->tex->offset * del;
	if (find_real_height(height) > WIN_Y)
	{
		data->tex->y = data->tex->height - ((WIN_Y * data->tex->height)
				/ (float)find_real_height(height));
		data->tex->y = data->tex->y / 2;
	}
	else
		data->tex->y = 0;
}
