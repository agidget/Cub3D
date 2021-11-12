/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:41:30 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:41:34 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*north_or_south(t_data *data)
{
	if (data->player.dir >= 180 && data->player.dir <= 360)
		return (data->no);
	else
		return (data->so);
}

char	*west_or_east(t_data *data)
{
	if (data->player.dir >= 90 && data->player.dir <= 270)
		return (data->we);
	else
		return (data->ea);
}

char	*west_or_south(t_data *data, int x, int y)
{
	if (find_walls(data->map, x + 1, y) != 1
		&& find_walls(data->map, x, y + 1) == 1)
	{
		if (data->player.dir >= 0 && data->player.dir <= 180)
			return (data->so);
		else
			return (data->we);
	}
	return (data->we);
}

char	*texture_for_corners(t_data *data, int x, int y)
{
	if (find_walls(data->map, x - 1, y) != 1
		&& find_walls(data->map, x, y - 1) == 1)
	{
		if (data->player.dir >= 135 && data->player.dir <= 315)
			return (data->no);
		else
			return (data->ea);
	}
	if (find_walls(data->map, x - 1, y) != 1
		&& find_walls(data->map, x, y + 1) == 1)
	{
		if (data->player.dir > 180 && data->player.dir <= 360)
			return (data->ea);
		else
			return (data->so);
	}
	if (find_walls(data->map, x + 1, y) != 1
		&& find_walls(data->map, x, y - 1) == 1)
	{
		if (data->player.dir >= 180 && data->player.dir <= 360)
			return (data->no);
		else
			return (data->we);
	}
	return (west_or_south(data, x, y));
}

void	find_texture(t_data *data, int x, int y)
{
	char	*texture;

	if (y % SIZE == 0 && x % SIZE != 0)
		texture = north_or_south(data);
	if (x % SIZE == 0 && y % SIZE != 0)
		texture = west_or_east(data);
	if (x % SIZE == 0 && y % SIZE == 0)
	{
		if (find_walls(data->map, x - 1, y) == 1
			&& find_walls(data->map, x + 1, y) == 1)
			texture = north_or_south(data);
		else if (find_walls(data->map, x, y + 1) == 1
			&& find_walls(data->map, x, y - 1) == 1)
			texture = west_or_east(data);
		else
			texture = texture_for_corners(data, x, y);
	}
	data->tex->img = mlx_xpm_file_to_image(data->win.mlx, texture,
			&data->tex->width, &data->tex->height);
	data->tex->addr = mlx_get_data_addr(data->tex->img, &data->tex->bpp,
			&data->tex->size_line, &data->tex->endian);
}
