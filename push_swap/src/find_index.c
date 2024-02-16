/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:39:53 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/16 17:36:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_in_a(t_data *a, t_data *b)
{
	int		i;
	t_lst	*buf;

	i = 0;
	buf = a->list;
	if (b->list->content < a->min || b->list->content > a->max)
	{
		while (i < a->size)
		{
			if (buf->content == a->min)
			{
				if (i > a->size / 2)
					i = i - a->size;
				return (i);
			}
			i++;
			buf = buf->next;
		}
	}
	else
	{
		while (i < a->size)
		{
			if (b->list->content > buf->prev->content &&
				b->list->content < buf->content)
			{
				if (i > a->size / 2)
					i = i - a->size;
				return (i);
			}
			i++;
			buf = buf->next;
		}
	}
	return (i);
}
