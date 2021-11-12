/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:16:56 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:18:56 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_all_file(t_list *list, t_data *data)
{
	char	*str;
	t_list	*tmp;
	int		i;

	tmp = list;
	while (tmp)
	{
		str = ft_strdup((char *)tmp->content);
		i = 0;
		while (str[i])
		{
			if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W'
				|| str[i] == 'E' || str[i] == 'F' || str[i] == 'C')
				break ;
			if (str[i] != ' ' && str[i] != '\0'
				&& str[i] != '1' && str[i] != '0')
			{
				free(str);
				file_error(list, data);
			}
			i++;
		}
		free(str);
		tmp = tmp->next;
	}
}

int	for_map_size(t_list *list, t_data *data, char *str)
{
	t_list	*tmp;
	int		size;

	tmp = list;
	size = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, str) == 0)
			break ;
		size++;
		tmp = tmp->next;
	}
	return (data->file_size - size);
}

void	arr_to_list_sp(t_list *list, t_data *data)
{
	t_list	*tmp;
	int		i;

	data->map = malloc(sizeof(char *) * (data->map_size + 1));
	malloc_error(data->map);
	tmp = list;
	i = -1;
	while (++i < data->file_size - data->map_size)
		tmp = tmp->next;
	i = 0;
	while (i < data->map_size)
	{
		data->map[i] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	data->map[i] = NULL;
}

void	fill_map(t_list *list, t_data *data, char *str, int *i)
{
	if (data->map_size == -1)
	{
		if (str[*i] == '1' || str[*i] == '0')
		{
			if (!data->no || !data->so || !data->we || !data->ea
				|| data->floor == -1 || data->ceil == -1)
				file_error(list, data);
			else
			{
				check_textures(list, data);
				data->map_size = for_map_size(list, data, str);
				arr_to_list_sp(list, data);
				*i = ft_strlen(str) - 1;
			}
		}
	}
	else
		return ;
}

void	fill_data(t_list *list, t_data *data, char *str, int *i)
{
	if (!data->map)
	{
		no_side(list, data, str, i);
		so_side(list, data, str, i);
		we_side(list, data, str, i);
		ea_side(list, data, str, i);
		floor_color(list, data, str, i);
		ceilling_color(list, data, str, i);
	}
	fill_map(list, data, str, i);
}
