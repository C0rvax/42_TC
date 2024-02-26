/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_q.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:28:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/26 15:29:04 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_q1(t_data *data, int q1, int med)
{
	int		count;
	int		i;
	t_lst	*buf;

	buf = data->list;
	count = 0;
	i = 0;
	while (i < data->size)
	{
		if (buf->content < q1)
			count--;
		if (buf->content >= q1 && buf->content < med)
			count++;
		i++;
		buf = buf->next;
	}
	if (data->size % 2 == 1)
		count--;
	return (count);
}

int	get_q1(t_data *data, int min, int med)
{
	int	q1;
	int	i;

	i = 0;
	if (med >= 0 && min < 0)
		q1 = (med + min) / 2;
	else
		q1 = med - ((med - min) / 2);
	i = is_q1(data, q1, med);
	while (i < -1 || i > 1)
	{
		if (i < 0)
			q1--;
		else
			q1++;
		i = is_q1(data, q1, med);
	}
	return (q1);
}

static int	is_q2(t_data *data, int q2, int med)
{
	int		count;
	int		i;
	t_lst	*buf;

	buf = data->list;
	count = 0;
	i = 0;
	while (i < data->size)
	{
		if (buf->content < q2 && buf->content >= med)
			count--;
		if (buf->content >= q2)
			count++;
		i++;
		buf = buf->next;
	}
	if (data->size % 2 == 1)
		count--;
	return (count);
}

int	get_q2(t_data *data, int med, int max)
{
	int	q2;
	int	i;

	i = 0;
	if (max >= 0 && med < 0)
		q2 = (max + med) / 2;
	else
		q2 = max - ((max - med) / 2);
	i = is_q2(data, q2, med);
	while (i < -1 || i > 1)
	{
		if (i < 0)
			q2--;
		else
			q2++;
		i = is_q2(data, q2, med);
	}
	return (q2);
}
