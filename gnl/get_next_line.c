/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:50:23 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:50:24 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_rem(char *rem)
{
	char	*check;

	if (!rem)
		return (0);
	check = ft_strchr(rem, '\n');
	if (check)
		return (1);
	return (0);
}

void	if_new_line(char **line, char **rem)
{
	char	*check;
	char	*tmp;
	char	*empty;

	if (*rem == NULL)
	{
		empty = "";
		*line = ft_strdup(empty);
		return ;
	}
	check = ft_strchr(*rem, '\n');
	if (!check)
	{
		*line = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
		return ;
	}
	tmp = *rem;
	*check = '\0';
	*line = ft_strdup(*rem);
	*rem = ft_strdup(++check);
	free(tmp);
}

void	rem_return(int ret, char *buf, char **rem)
{
	if (ret != 0)
		*rem = ft_strjoin_mod(*rem, buf);
}

int	return_value(int ret)
{
	if (ret)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			ret;
	static char	*rem;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	ret = 1;
	while (!check_rem(rem) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			*line = NULL;
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		rem_return(ret, buf, &rem);
	}
	if_new_line(line, &rem);
	free(buf);
	return (return_value(ret));
}
