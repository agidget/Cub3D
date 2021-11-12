/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:15:07 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:16:17 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

//coordinate system - tope left angle is center (0, 0)
void	general_map_check(t_list *list, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_size)
	{
		j = 0;
		while (data->map[i][j])
		{
			avail_chars_map(list, data, i, j);
			if_space_in_map(list, data, i, j);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				if (data->player.x != -1 || data->player.y != -1
					|| data->player.dir != -1)
					map_error(list, data);
				data->player.x = j * SIZE + SIZE / 2;
				data->player.y = i * SIZE + SIZE / 2;
				data->player.dir = find_dir((int)data->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	check_borders_top_bottom(t_list *list, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if_space_error(list, data, 0, i);
		if_space_in_map(list, data, 0, i);
		i++;
	}
	i = 0;
	while (data->map[data->map_size - 1][i])
	{
		if_space_error(list, data, data->map_size - 1, i);
		if_space_in_map(list, data, data->map_size - 1, i);
		i++;
	}
}

void	check_borders_left_right(t_list *list, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_size)
	{
		if_space_error(list, data, i, 0);
		if_space_in_map(list, data, i, 0);
		i++;
	}
	i = 0;
	while (i < data->map_size)
	{
		if_space_error(list, data, i, ft_strlen(data->map[i]) - 1);
		if_space_in_map(list, data, i, ft_strlen(data->map[i]) - 1);
		i++;
	}
}

void	check_borders(t_list *list, t_data *data)
{
	check_borders_top_bottom(list, data);
	check_borders_left_right(list, data);
}

void	check_map(t_list *list, t_data *data)
{
	int	i;
	int	j;

	check_borders(list, data);
	general_map_check(list, data);
	if (data->player.x == -1 || data->player.y == -1
		|| data->player.dir == -1)
		map_error(list, data);
}
