/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:39:53 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/17 22:36:50 by aduvilla         ###   ########.fr       */
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
		i = find_content(a, a->min);
		return (i);
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

int	cost_max_min(int i, int j)
{
	if (i < 0 && j < 0)
	{
		i *= -1;
		j *= -1;
	}
	if (i >= 0 && j < 0)
	{
		j *= -1;
		i = i + j;
	}
	if (i < 0 && j >= 0)
	{
		i *= -1;
		j = j + i;
	}
	if (i >= j)
		return (i);
	else
		return (j);
}

void	check_cost_up(t_data *a, t_data *b, int *rota, int *rotb, int *cost)
{
	int	i;
	int	j;
	t_lst	*lst;


	i = 0;
	lst = a->list;
	while (i <= a->size)
	{
		j = find_in_b(b, lst->content);
		if (cost_max_min(i, j) < *cost)
		{
			*rota = i;
			*rotb = j;
			*cost = cost_max_min(i, j);
		}
		i++;
		lst = lst->next;
	}
}

void	check_cost_down(t_data *a, t_data *b, int *rota, int *rotb, int *cost)
{
	int	i;
	int	j;
	t_lst	*lst;

	i = -1;
	lst = a->list->prev;
	while (i >= -*cost)
	{
		j = find_in_b(b, lst->content);
		if (cost_max_min(i, j) < *cost)
		{
			*rota = i;
			*rotb = j;
			*cost = cost_max_min(i, j);
		}
		i--;
		lst = lst->prev;
	}
}

int	get_max_min(int i, int j)
{
	if (i <= j)
		return (i);
	else
		return (j);
}

void	all_in_b(t_data *a, t_data *b)
{
	int	rota;
	int	rotb;
	int	cost;

	cost = a->size / 2 + b->size / 2;
	check_cost_up(a, b, &rota, &rotb, &cost);
	check_cost_down(a, b, &rota, &rotb, &cost);
	if ((rota >= 0 && rotb < 0) || (rota < 0 && rotb >=0))
	{
		rotate_list(&a->list, &b->list, rota, 1);
		rotate_list(&b->list, &a->list, rotb, 3);
	}
	else
	{
		cost = get_max_min(rotb, rota);
		rotate_list(&a->list, &b->list, cost, 2);
		if (cost == rotb)
			rotate_list(&a->list, &b->list, rota - cost, 1);
		else
			rotate_list(&b->list, &b->list, rotb - cost, 3);
	}
}

int	find_in_b(t_data *b, int acontent)
{
	int		i;
	t_lst	*buf;

	if (b->size < 2)
		return (0);
	buf = b->list;
	if (acontent < b->min || acontent > b->max)
		i = find_content(b, b->max);
	else
	{
		i = 0;
		while (i < b->size)
		{
			if (acontent < buf->prev->content && acontent > buf->content)
			{
				if (i > b->size / 2)
					i = i - b->size;
				break;
			}
			i++;
			buf = buf->next;
		}
	}
	return (i);
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
	return (ft_printf("Error\nPas trouvé la value!"));
}
