/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:53:41 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/21 11:04:18 by aduvilla         ###   ########.fr       */
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

void	set_pointers_to_null(t_lst **p1, t_lst **p2)
{
	*p1 = NULL;
	*p2 = NULL;
}

void	set_2p(t_lst **p1, t_lst *p2, t_lst **pt1, t_lst *pt2)
{
	*p1 = p2;
	*pt1 = pt2;
}
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
