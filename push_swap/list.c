/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:06:35 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 11:37:30 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_listclear(t_lst **lst)
{
	t_lst	*buf;

	while(lst)
	{
		buf = (*lst)->next;
		free(*lst);
		*lst = buf;
	}
	free(*lst);
	*lst = NULL;
}

t_lst	*ft_listnew(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_lst	*ft_listlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_listadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*buf;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		buf = ft_listlast(*lst);
		buf->next = new;
	}
}
