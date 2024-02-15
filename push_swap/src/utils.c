/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:53:41 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/15 14:30:28 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_list_max(t_data *data)
{
	int		i;
	t_lst	*buf;

	i = 0;
	buf = data->list;
	if (buf->content > data->max)
		data->max = buf->content;
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
