/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:12:14 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:12:42 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	color_font(char *str, int *i, t_list *list, t_data *data)
{
	char	*c_str;
	char	**arr;
	int		color;

	*i += 2;
	c_str = texture_link(str, i);
	arr = ft_split(c_str, ',');
	free(c_str);
	if (arr_size(arr) != 3)
		error_color(arr, list, data);
	color = create_rgb(ft_atoi_mod(arr[0], arr, list, data),
			ft_atoi_mod(arr[1], arr, list, data),
			ft_atoi_mod(arr[2], arr, list, data));
	for_free(arr);
	return (color);
}

void	floor_color(t_list *list, t_data *data, char *str, int *i)
{
	if (str[*i] == 'F')
	{
		if (str[*i + 1] == ' ' && str[*i + 2])
		{
			data->floor = color_font(str, i, list, data);
			check_after_link(list, data, str, i);
		}
		else
			file_error(list, data);
	}
}

void	ceilling_color(t_list *list, t_data *data, char *str, int *i)
{
	if (str[*i] == 'C')
	{
		if (str[*i + 1] == ' ' && str[*i + 2])
		{
			data->ceil = color_font(str, i, list, data);
			check_after_link(list, data, str, i);
		}
		else
			file_error(list, data);
	}
}
