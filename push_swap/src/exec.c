/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:24:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/27 13:53:18 by aduvilla         ###   ########.fr       */
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

static t_lst	*extract_from_list(t_data *data)
{
	t_lst	*buf_n;
	t_lst	*buf_p;
	t_lst	*node;

	node = data->list;
	if (data->size == 1)
		data->list = NULL;
	else
	{
		buf_n = data->list->next;
		buf_p = data->list->prev;
		data->list = buf_n;
		set_2p(&node->next, NULL, &node->prev, NULL);
		if (data->size > 2)
		{
			buf_n->prev = buf_p;
			buf_p->next = buf_n;
		}
		if (data->size == 2)
			set_2p(&buf_n->next, NULL, &buf_n->prev, NULL);
	}
	data->size--;
	return (node);
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
		set_2p(&out->list->prev, node, &out->list->next, node);
		set_2p(&node->prev, out->list, &node->next, out->list);
	}
	else if (out->size > 1)
	{
		buf_p = out->list->prev;
		set_2p(&buf_p->next, node, &out->list->prev, node);
		set_2p(&node->next, out->list, &node->prev, buf_p);
	}
	out->list = node;
	out->size++;
	if (node->content > out->max || node->content < out->min)
		set_list_max(out);
	return (p);
}

static void	push_it(t_data *a, t_data *b, int med)
{
	int	val;

	val = a->list->content;
	exec_push(ft_printf("pb\n"), a, b);
	if (val >= med && b->size > 1)
		rotate_list(&b->list, &a->list, 1, 3);
}

void	push_in_b(t_data *a, t_data *b)
{
	int	q1;
	int	q2;
	int	med;
	int	val;
	int	size;

	med = get_med(a, a->min, a->max);
	q1 = get_q1(a, a->min, med);
	q2 = get_q2(a, med, a->max);
	size = a->size;
	while (size)
	{
		val = a->list->content;
		if (val >= q1 && val <= q2)
			rotate_list(&a->list, &b->list, 1, 1);
		else
			push_it(a, b, med);
		size--;
	}
	while (a->size > 3)
		push_it(a, b, med);
}
/*
void	rotate_list_mute(t_lst **first, t_lst **sec, int i, int mode)
{
	if (i < 0)
	{
		i *= -1;
		while (i > 0)
		{
			if (mode == 2)
				exec_rotate(4, sec);
			exec_rotate(4 , first);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			if (mode == 2)
				exec_rotate(3, sec);
			exec_rotate(3, first);
			i--;
		}
	}
}
*/
