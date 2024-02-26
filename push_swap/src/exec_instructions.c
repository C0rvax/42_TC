/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:09:22 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/27 00:34:53 by aduvilla         ###   ########.fr       */
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
	ft_printf("nod c : %d\n", node->content);
	if (data->size > 1)
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
	ft_printf("p node : %p\n", node);
	ft_printf("nod c : %d\n", node->content);
	return (node);
}

int	exec_push(int p, t_data *in, t_data *out)
{
	t_lst	*buf_p;
	t_lst	*node;

	ft_printf("in node : %d\n", in->list->content);
	node = extract_from_list(in);
	ft_printf("size : %d\n", in->size);
	ft_printf("min : %d max %d\n", in->min, in->max);
	ft_printf("node cont : %d\n", node->content);
	if ((node->content == in->max || node->content == in->min) && in->size > 0)
	{
		ft_printf("apres test!\n");
		set_list_max(in);
	}
	ft_printf("apres test!\n");
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
	char	**array;
	int		i;

	line = get_all_lines(0);
//	line = get_next_line(0);
	if (!line)
		ft_putstr_fd("Error\n", 2);
	array = ft_split(line, '\n');
	free(line);
	i = 0;
	while (array[i])
	{
		if (!ft_strncmp(array[i], "ra", 2))
			exec_rotate(3, &a->list);
		if (!ft_strncmp(array[i], "rb", ft_strlen(array[i])))
			exec_rotate(3, &b->list);
		ft_printf("avant pa\n");
		if (!ft_strncmp(array[i], "pa", 2))
			exec_push(3, b, a);
		ft_printf("apres pa\n");
		if (!ft_strncmp(array[i], "pb", 2))
			exec_push(3, a, b);
		if (!ft_strncmp(array[i], "rr", 2))
		{
			exec_rotate(3, &b->list);
			exec_rotate(3, &a->list);
		}
		if (!ft_strncmp(array[i], "rrr", 3))
		{
			exec_rotate(4, &b->list);
			exec_rotate(4, &a->list);
		}
		ft_printf("ok\n");
		if (!ft_strncmp(array[i], "rra", 3))
		{
			ft_printf("avant rra\n");
			exec_rotate(4, &a->list);
		}
		ft_printf("apres rra\n");
		if (!ft_strncmp(array[i], "rrb", 3))
			exec_rotate(4, &b->list);
		if (!ft_strncmp(array[i], "sa", 2))
			exec_swap(3, a);
		if (!ft_strncmp(array[i], "sb", 2))
			exec_swap(3, b);
		i++;
	}
	ft_printf("ok\n");
}
