/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:24:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/14 10:25:54 by aduvilla         ###   ########.fr       */
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
	if (p == 2)
		*list = (*list)->next;
	else
		*list = (*list)->prev;
	return (p);
}

void	set_max(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->list->content > data->max)
			data->max = data->list->content;
		data->list = data->list->next;
	}
}

int	exec_push(int p, t_data *in, t_data *out)
{
	t_lst	*buf_n;
	t_lst	*buf_p;
	t_lst	*node;

	node = in->list;
	buf_n = in->list->next;
	buf_p = in->list->prev;
	buf_n->prev = buf_p;
	buf_p->next = buf_n;
	in->size--;
	ft_printf("push1\n");
	ft_printf("max : %d\n", in->max);
	if (node->content == in->max)
		set_max(in);
	ft_printf("la\n");
	buf_p = out->list->prev;
	buf_p->next = node;
	out->list->prev = node;
	ft_printf("la2\n");
	out->size++;
	ft_printf("la2\n");
	if (node->content > out->max)
		set_max(out);
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
