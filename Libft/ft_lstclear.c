/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gflores <gflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:46:12 by gflores           #+#    #+#             */
/*   Updated: 2021/10/08 11:46:13 by gflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cl;

	if (!lst)
		return ;
	while (*lst)
	{
		cl = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cl;
	}
}
