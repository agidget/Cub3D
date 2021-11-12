/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:19:06 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:19:07 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	file_error(t_list *list, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Data from the file is incorrect\n", 2);
	free_list(list);
	free_data(data);
	exit(EXIT_FAILURE);
}

void	link_error(t_list *list, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Link for a texture is incorrect\n", 2);
	free_list(list);
	free_data(data);
	exit(EXIT_FAILURE);
}
