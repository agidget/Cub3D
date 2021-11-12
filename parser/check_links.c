/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:10:39 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:12:05 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*texture_link(char *str, int *i)
{
	int		j;
	char	*orien;
	int		k;

	j = 0;
	while (str[*i + j] != ' ' && str[*i + j])
		j++;
	orien = malloc(sizeof(char) * (j + 1));
	malloc_error(orien);
	k = 0;
	while (k < j)
	{
		orien[k] = str[*i + k];
		k++;
	}
	orien[k] = '\0';
	*i += j;
	return (orien);
}

void	check_link(char *str, t_list *list, t_data *data)
{
	int		fd;
	char	*format;
	int		i;

	format = malloc(sizeof(char) * 5);
	malloc_error(format);
	i = 0;
	while (i < 4)
	{
		format[i] = str[ft_strlen(str) - 4 + i];
		i++;
	}
	format[i] = '\0';
	fd = open(str, O_RDONLY);
	if (fd == -1 || ft_strncmp(format, ".xpm", 4) != 0)
	{
		free(format);
		link_error(list, data);
	}
	free(format);
	close(fd);
}

void	check_textures(t_list *list, t_data *data)
{
	if (data->no)
		check_link(data->no, list, data);
	if (data->so)
		check_link(data->so, list, data);
	if (data->we)
		check_link(data->we, list, data);
	if (data->ea)
		check_link(data->ea, list, data);
}

void	check_after_link(t_list *list, t_data *data, char *str, int *i)
{
	int	k;

	k = *i;
	while (str[k] && str[k] == ' ')
		k++;
	if (str[k] != '\0' && str[k] != 'N' && str[k] != 'S' && str[k] != 'W'
		&& str[k] != 'E' && str[k] != 'F' && str[k] != 'C')
		file_error(list, data);
}
