/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:09:22 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/26 13:41:39 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	exec_rotate(int p, t_lst **list)
{
	if (p == 3)
		*list = (*list)->next;
	else
		*list = (*list)->prev;
	return (p);
}

void	exec_instructions(t_data *a, t_data *b)
{
	char	*line;

	line = get_all_lines(0);
//	line = get_next_line(0);
	if (!line)
		ft_putstr_fd("Error\n", 2);
//	ft_printf("line : %s\n", line);
	ft_printf("line : %s\n", line);
	while (line)
	{
		ft_printf("jusqu'ici tout va bien!\n");
		if (ft_strncmp(line, "ra\n", 3))
			exec_rotate(3, &a->list);
		if (ft_strncmp(line, "rb\n", 3))
			exec_rotate(3, &b->list);
		if (ft_strncmp(line, "pa\n", 3))
			exec_push(3, b, a);
		if (ft_strncmp(line, "pb\n", 3))
		{
			printf("dans le comp\n");
			exec_push(3, a, b);
		}
		if (ft_strncmp(line, "rr\n", 3))
		{
			exec_rotate(3, &b->list);
			exec_rotate(3, &a->list);
		}
		if (ft_strncmp(line, "rrr\n", 4))
		{
			exec_rotate(4, &b->list);
			exec_rotate(4, &a->list);
		}
		if (ft_strncmp(line, "rra", 4))
			exec_rotate(4, &a->list);
		if (ft_strncmp(line, "rrb", 4))
			exec_rotate(4, &b->list);
		if (ft_strncmp(line, "sa", 3))
			exec_swap(3, a);
		if (ft_strncmp(line, "sb", 3))
			exec_swap(3, b);
		free(line);
		line = get_next_line(0);
	}
}
