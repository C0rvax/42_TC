/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:39:53 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/16 18:36:38 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_in_a(t_data *a, int bcontent)
{
	int		i;
	t_lst	*buf;

	i = 0;
	buf = a->list;
	if (bcontent < a->min || bcontent > a->max)
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
			if (bcontent > buf->prev->content && bcontent < buf->content)
			{
				if (i > a->size / 2)
					i = i - a->size;
				return (i);
			}
			i++;
			buf = buf->next;
		}
	}
	return (ft_printf("Error\nPas trouvé dans a!"));
}

int	find_content(t_data *data, int value)
{
	int		i;
	t_lst	*lst;

	i = 0;
	lst = data->list;
	while (i < data->size)
	{
		if (lst->content == value)
		{
			if (i > data->size / 2)
				i = i - data->size;
			return (i);
		}
		i++;
		lst = lst->next;
	}
	return (ft_printf("Error\nPas trouvé dans a!"));
}
