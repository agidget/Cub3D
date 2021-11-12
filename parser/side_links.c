/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:16:43 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:16:45 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	no_side(t_list *list, t_data *data, char *str, int *i)
{
	if (str[*i] == 'N' && ft_strlen(str) > 3)
	{
		if (str[*i + 1] == 'O' && str[*i + 2] == ' ' && str[*i + 3])
		{
			*i += 3;
			data->no = texture_link(str, i);
			check_after_link(list, data, str, i);
			return ;
		}
		else
			file_error(list, data);
	}
}

void	so_side(t_list *list, t_data *data, char *str, int *i)
{
	if (str[*i] == 'S')
	{
		if (str[*i + 1] == 'O' && str[*i + 2] == ' ' && str[*i + 3])
		{
			*i += 3;
			data->so = texture_link(str, i);
			check_after_link(list, data, str, i);
			return ;
		}
		else
			file_error(list, data);
	}
}

void	we_side(t_list *list, t_data *data, char *str, int *i)
{
	if (str[*i] == 'W')
	{
		if (str[*i + 1] == 'E' && str[*i + 2] == ' ' && str[*i + 3])
		{
			*i += 3;
			data->we = texture_link(str, i);
			check_after_link(list, data, str, i);
			return ;
		}
		else
			file_error(list, data);
	}
}

void	ea_side(t_list *list, t_data *data, char *str, int *i)
{
	if (str[*i] == 'E')
	{
		if (str[*i + 1] == 'A' && str[*i + 2] == ' ' && str[*i + 3])
		{
			*i += 3;
			data->ea = texture_link(str, i);
			check_after_link(list, data, str, i);
			return ;
		}
		else
			file_error(list, data);
	}
}
