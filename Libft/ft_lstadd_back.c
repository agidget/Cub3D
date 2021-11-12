/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:46:03 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:46:05 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*old;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	old = *lst;
	while (old->next)
		old = old->next;
	new->next = NULL;
	old->next = new;
}
