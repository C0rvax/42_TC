/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:24:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/17 22:50:48 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_swap(int p, t_data *data)
{
	int		buf;

	buf = data->list->content;
	data->list->content = data->list->next->content;
	data->list->next->content = buf;
	return (p);
}

int	exec_rotate(int p, t_lst **list)
{
	if (p == 3)
		*list = (*list)->next;
	else
		*list = (*list)->prev;
	return (p);
}

int	exec_push(int p, t_data *in, t_data *out)
{
	t_lst	*buf_p;
	t_lst	*node;
	node = extract_from_list(in);
	if ((node->content == in->max || node->content == in->min) && in->size > 0)
		set_list_max(in);
	if (out->size == 1)
	{
		out->list->prev = node;
		out->list->next = node;
		node->next = out->list;
		node->prev = out->list;
	}
	else if (out->size > 1)
	{
		buf_p = out->list->prev;
		buf_p->next = node;
		out->list->prev = node;
		node->next = out->list;
		node->prev = buf_p;
	}
	out->list = node;
	out->size++;
	if (node->content > out->max || node->content < out->min)
		set_list_max(out);
	return (p);
}
