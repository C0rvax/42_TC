/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:39:53 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/15 15:21:00 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_in_a(t_data *a, t_data *b)
{
	int		i;
	int		j;
	t_lst	*buf;

	i = 0;
	j = b->list->content + 1;
	buf = a->list;
	ft_printf("a min : %d a max : %d\n", a->min, a->max);
	if (b->list->content < a->min || b->list->content > a->max)
	{
		ft_printf("dans le min max\n");
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
		while (j < a->max)
		{
			i = 0;
			while (i < a->size)
			{
				if (j == buf->content)
				{
					ft_printf("j = %d\n", j);
					ft_printf("a size div 2 = %d\n", a->size /2);
					if (i > (a->size / 2))
					{
						ft_printf("i = %d", i);
						i = i - a->size;
					}
					return (i);
				}
				i++;
				buf = buf->next;
			}
			j++;
		}
	}
	return (i);
}
