/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:50:18 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:50:21 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if ((!s1 && !s2) || !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}
