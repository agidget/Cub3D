/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:50:27 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:51:20 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"

# define BUFFER_SIZE 1024

char	*ft_strjoin_mod(char *s1, char *s2);
int		check_rem(char *rem);
void	if_new_line(char **line, char **rem);
int		get_next_line(int fd, char **line);
void	rem_return(int ret, char *buf, char **rem);
int		return_value(int ret);

#endif
