/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:53:41 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/26 16:18:43 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_list_max(t_data *data)
{
	int		i;
	t_lst	*buf;

	i = 0;
	data->max = -2147483648;
	data->min = 2147483647;
	buf = data->list;
	if (buf->content > data->max)
		data->max = buf->content;
	if (buf->content < data->min)
		data->min = buf->content;
	while (i < data->size && data->size > 1)
	{
		if (buf->content > data->max)
			data->max = buf->content;
		if (buf->content < data->min)
			data->min = buf->content;
		buf = buf->next;
		i++;
	}
}

void	set_2p(t_lst **p1, t_lst *p2, t_lst **pt1, t_lst *pt2)
{
	*p1 = p2;
	*pt1 = pt2;
}

int	u_never_know(t_data *a)
{
	int		i;
	t_lst	*list;

	i = 0;
	list = a->list;
	while (i < a->size - 1)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

static int	is_med(t_data *data, int med)
{
	int		count;
	int		i;
	t_lst	*buf;

	buf = data->list;
	count = 0;
	i = 0;
	while (i < data->size)
	{
		if (buf->content < med)
			count--;
		if (buf->content >= med)
			count++;
		i++;
		buf = buf->next;
	}
	if (data->size % 2 == 1)
		count--;
	return (count);
}

int	get_med(t_data *data, int min, int max)
{
	int	med;
	int	i;

	i = 0;
	if (max >= 0 && min < 0)
		med = (max + min) / 2;
	else
		med = max - ((max - min) / 2);
	i = is_med(data, med);
	while (i != 0)
	{
		if (i < 0)
			med--;
		else
			med++;
		i = is_med(data, med);
	}
	return (med);
}
/*
void	print_list(t_data *data)
{
	int	i;

	i = 0;
	if (data->size == 1)
		ft_printf("a[0] = %d\n", data->list->content);
	while (i < data->size && data->size > 1)
	{
		ft_printf("a[%d] = %d\n", i, data->list->content);
		data->list = data->list->next;
		i++;
	}
}
*/
