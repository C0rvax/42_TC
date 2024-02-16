/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:24:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/16 19:11:34 by aduvilla         ###   ########.fr       */
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
/*	t_lst	*buf_p;

	node = in->list;
	if (in->size == 1)
		in->list = NULL;
	else
	{
		buf_n = in->list->next;
		buf_p = in->list->prev;
		in->list = buf_n;
		node->next = NULL;
		node->prev = NULL;
		if (in->size > 2)
		{
			buf_n->prev = buf_p;
			buf_p->next = buf_n;
		}
		if (in->size == 2)
		{
			buf_n->prev = NULL;
			buf_n->next = NULL;
		}
	}
	in->size--;
	*/
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

int	exec_reverse(int p,int *stack, int size)
{
	int	i;
	int	buf;

	i = size - 1;
	buf = stack[i];
	while (i)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = buf;
	return (p);
}
