/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:06:35 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/21 11:20:57 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_listclear(t_data *data)
{
	int		i;
	t_lst	*buf;

	i = 0;
	while (i < data->size - 1)
	{
		buf = data->list->next;
		free(data->list);
		data->list = buf;
		i++;
	}
	free(data->list);
	data->list = NULL;
}

t_lst	*ft_listnew(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_listadd_front(t_data *data, t_lst *new)
{
	if (!new)
		return ;
	new->next = data->list;
	data->list->prev = new;
	data->list = new;
}
