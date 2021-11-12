/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <agidget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:14:04 by agidget           #+#    #+#             */
/*   Updated: 2021/10/02 18:15:00 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	if_error(void)
{
	ft_putstr_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}

t_list	*read_file(char *arg)
{
	int		fd;
	char	*line;
	t_list	*file;

	line = NULL;
	file = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		if_error();
	while (get_next_line(fd, &line))
		ft_lstadd_back(&file, ft_lstnew(line));
	ft_lstadd_back(&file, ft_lstnew(line));
	return (file);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}

void	check_list(t_list *list, t_data *data)
{
	t_list	*tmp;
	int		i;
	char	*str;

	tmp = list;
	check_all_file(list, data);
	while (tmp)
	{
		str = ft_strdup((char *)tmp->content);
		i = 0;
		while (str[i] && i < ft_strlen(str) - 1)
		{
			fill_data(list, data, str, &i);
			i++;
		}
		free(str);
		tmp = tmp->next;
	}
	if (!data->map || !data->no || !data->so || !data->we || !data->ea
		|| data->floor == -1 || data->ceil == -1)
		file_error(list, data);
	check_map(list, data);
}

void	main_parser(char **argv, t_data	**data)
{
	t_list	*list;

	*data = init_data();
	list = read_file(argv[1]);
	(*data)->file_size = ft_lstsize(list);
	check_list(list, *data);
	free_list(list);
}
