/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:12:53 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:12:56 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	for_free(char **new)
{
	size_t	i;

	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
}

int	arr_size(char **arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void	error_color(char **arr, t_list *list, t_data *data)
{
	for_free(arr);
	file_error(list, data);
}

int	ft_atoi_mod(char *str, char **arr, t_list *list, t_data *data)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (str[0] == '\0')
		num = -1;
	if (str[0] == '+' || (str[0] == '-' && str[1] == '0'))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			num = num * 10 + str[i] - '0';
		else
		{
			num = -1;
			break ;
		}
		i++;
	}
	if (num > 255 || num == -1)
		error_color(arr, list, data);
	return (num);
}
