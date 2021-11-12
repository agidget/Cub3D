/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:13:45 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:13:47 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	malloc_error(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("Error with malloc\n", 2);
		exit(EXIT_FAILURE);
	}
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	malloc_error(data);
	data->tex = malloc(sizeof(t_tex) * 1);
	data->tex->img = NULL;
	data->tex->x = 0;
	data->tex->y = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor = -1;
	data->ceil = -1;
	data->map_size = -1;
	data->map = NULL;
	data->player.x = -1;
	data->player.y = -1;
	data->player.dir = -1;
	return (data);
}

void	free_data(t_data *data)
{
	free(data->tex);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	if (data->map)
		for_free(data->map);
	free(data);
}
