/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:09:22 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/27 14:23:21 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	exec_swap(t_data *a, t_data *b, int mode)
{
	int		buf;

	if ((mode == 0 || mode == 2) && a->size >= 2)
	{
		buf = a->list->content;
		a->list->content = a->list->next->content;
		a->list->next->content = buf;
	}
	if ((mode == 1 || mode == 2) && b->size >= 2)
	{
		buf = b->list->content;
		b->list->content = b->list->next->content;
		b->list->next->content = buf;
	}
	return (1);
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

	if (in->size == 0)
		return (p);
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

static int	exec_rotate(int p, t_lst **list)
{
	if (p == 3)
		*list = (*list)->next;
	else
		*list = (*list)->prev;
	return (p);
}

int	indexe(t_data *a, t_data *b, char **cmd, char *instruction)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(instruction);
	while (cmd[i])
	{
		if (!ft_strncmp(cmd[i], instruction, len))
			return (i);
		i++;
	}
	return (i);
}

void	rotate_list(t_lst **a, t_lst **b, int index)
{
	if (index == 5 || index == 7)
	{
		if ((*a)->next)
			*a = (*a)->next;
	}
	if (index == 6 || index == 7)
	{
		*b = (*b)->next;
	}
	if (index == 8 || index == 10)
	{
		*a = (*a)->prev;
	}
	if (index == 9 || index == 10)
	{
		*b = (*b)->prev;
	}
}
int	exec_instructions(t_data *a, t_data *b, char **cmd, char **instructions)
{
	int		i;
	int		index;

	i = 0;
	while (instructions[i])
	{
		index = indexe(a, b, cmd, instructions[i]);
		if (index < 3)
			exec_swap(a, b, index);
		if (index == 3)
			exec_push(3, a, b);
		if (index == 4)
			exec_push(3, b, a);
		else
			rotate_list(a, b, index);
		i++;
	}
}
