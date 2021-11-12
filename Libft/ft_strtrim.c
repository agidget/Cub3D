/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:47:54 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:47:55 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	check_end(char const *s1, char const *set, int i)
{
	int	j;
	int	k;

	k = ft_strlen(s1) - 1;
	while (k > i)
	{
		j = 0;
		while (set[j])
		{
			if (s1[k] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		k--;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	int		l;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	i = check_start(s1, set);
	k = check_end(s1, set, i);
	new = malloc(sizeof(*new) * (k - i + 1) + 1);
	if (!new)
		return (NULL);
	if (k - i == -1)
	{
		new[0] = '\0';
		return (new);
	}
	l = -1;
	while (++l <= k - i)
		new[l] = s1[i + l];
	new[l] = '\0';
	return (new);
}
