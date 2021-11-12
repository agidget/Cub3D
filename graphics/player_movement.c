/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:42:16 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:42:18 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	find_walls(char **map, int x, int y)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (map[a] != NULL)
	{
		while (map[a][b] != '\0')
		{
			if (map[a][b] == '1')
				if (x >= b * SIZE && x <= b * SIZE + SIZE)
					if (y >= a * SIZE && y <= a * SIZE + SIZE)
						return (1);
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

void	move_left_right(t_data *data, int *x, int *y, int keycode)
{
	if (keycode == LEFT)
	{
		*x = *x + SPEED * sin((data->player.dir) * PI / 180.0);
		*y = *y - SPEED * cos((data->player.dir) * PI / 180.0);
	}
	if (keycode == RIGHT)
	{
		*x = *x - SPEED * sin((data->player.dir) * PI / 180.0);
		*y = *y + SPEED * cos((data->player.dir) * PI / 180.0);
	}
}

int	change_position(t_data *data, int *x, int *y, int keycode)
{
	if (keycode == LEFT || keycode == RIGHT)
		move_left_right(data, x, y, keycode);
	if (keycode == UP)
	{
		*x = *x + SPEED * cos((data->player.dir) * PI / 180.0);
		*y = *y + SPEED * sin((data->player.dir) * PI / 180.0);
	}
	if (keycode == DOWN)
	{
		*x = *x - SPEED * cos((data->player.dir) * PI / 180.0);
		*y = *y - SPEED * sin((data->player.dir) * PI / 180.0);
	}
	if ((*y >= 0 && *x >= 0)
		&& find_walls(data->map, *x, *y) == 0)
		return (1);
	else
		return (0);
}

void	turn_around(int keycode, t_data **data)
{
	if (keycode == L_ARR)
	{
		(*data)->player.dir -= 5;
		if ((*data)->player.dir < 0)
			(*data)->player.dir = 355;
		mlx_clear_window ((*data)->win.mlx, (*data)->win.win);
		raycasting(*data);
	}
	if (keycode == R_ARR)
	{
		(*data)->player.dir += 5;
		if ((*data)->player.dir > 360)
			(*data)->player.dir = 5;
		mlx_clear_window ((*data)->win.mlx, (*data)->win.win);
		raycasting(*data);
	}
	if ((*data)->player.dir == 359 || (*data)->player.dir == -359)
		(*data)->player.dir = 0;
}

void	player_movement(t_data *data, int keycode)
{
	int		x;
	int		y;

	x = data->player.x;
	y = data->player.y;
	if (change_position(data, &x, &y, keycode) == 1)
	{
		data->player.x = x;
		data->player.y = y;
	}
}
