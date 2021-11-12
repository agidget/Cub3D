/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:16:27 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:16:28 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	map_error(t_list *list, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Data of the map is incorrect\n", 2);
	free_list(list);
	free_data(data);
	exit(EXIT_FAILURE);
}

void	if_space_error(t_list *list, t_data *data, int a, int b)
{
	if (data->map[a][b] != ' ' && data->map[a][b] != '1')
		map_error(list, data);
}

void	avail_chars_map(t_list *list, t_data *data, int a, int b)
{
	if (data->map[a][b] != ' ' && data->map[a][b] != '1' &&
		data->map[a][b] != '0' && data->map[a][b] != 'N' &&
		data->map[a][b] != 'S' && data->map[a][b] != 'E' &&
		data->map[a][b] != 'W')
		map_error(list, data);
}

void	check_if_space_correct(t_list *list, t_data *data, int i, int j)
{
	if (i != 0)
	{
		if (j != 0 && ft_strlen(data->map[i - 1]) > j - 1)
			if_space_error(list, data, i - 1, j - 1);
		if (ft_strlen(data->map[i - 1]) > j)
			if_space_error(list, data, i - 1, j);
		if (ft_strlen(data->map[i - 1]) > j + 1)
			if_space_error(list, data, i - 1, j + 1);
	}
	if (j != 0)
	{
		if_space_error(list, data, i, j - 1);
		if (data->map[i + 1])
			if_space_error(list, data, i + 1, j - 1);
	}
	if (data->map[i + 1])
	{
		if_space_error(list, data, i + 1, j);
		if (ft_strlen(data->map[i + 1]) > j + 1)
			if_space_error(list, data, i + 1, j + 1);
	}
	if (ft_strlen(data->map[i]) > j + 1)
		if_space_error(list, data, i, j + 1);
}

void	if_space_in_map(t_list *list, t_data *data, int i, int j)
{
	if (data->map[i][j] == ' ')
		check_if_space_correct(list, data, i, j);
}
