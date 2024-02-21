/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:03:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/21 12:39:06 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_min(int i, int j)
{
	if (i <= j)
		return (i);
	else
		return (j);
}

static int	cost_max_min(int i, int j)
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

static void	check_cost_up(t_data *a, t_data *b, int *rota, int *rotb, int *cost)
{
	int		i;
	int		j;
	t_lst	*lst;

	i = 0;
	lst = b->list;
	if (b->size < 2)
	{
		*rotb = 0;
		*rota = find_in_a(a, lst->content);
		*cost = cost_max_min(*rota, *rotb);
		return ;
	}
	while (i < b->size)
	{
		j = find_in_a(a, lst->content);
		if (cost_max_min(i, j) < *cost)
		{
			*rotb = i;
			*rota = j;
			*cost = cost_max_min(i, j);
		}
		i++;
		lst = lst->next;
	}
}

static void	check_cost_down(t_data *a, t_data *b, int *rota, int *rotb, int *cost)
{
	int		i;
	int		j;
	t_lst	*lst;

	i = -1;
	lst = b->list->prev;
	while (i >= -*cost && i >= -b->size)
	{
		j = find_in_a(a, lst->content);
		if (cost_max_min(i, j) < *cost)
		{
			*rotb = i;
			*rota = j;
			*cost = cost_max_min(i, j);
		}
		i--;
		lst = lst->prev;
	}
}

void	all_in_a(t_data *a, t_data *b)
{
	int	rota;
	int	rotb;
	int	cost;

	cost = a->size + b->size ;
	if (b->size < 2)
	{
		rotb = 0;
		rota = find_in_a(a, b->list->content);
		cost = cost_max_min(rota, rotb);
	}
	else
	{
		check_cost_up(a, b, &rota, &rotb, &cost);
		check_cost_down(a, b, &rota, &rotb, &cost);
	}
	if ((rota >= 0 && rotb < 0) || (rota < 0 && rotb >= 0))
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
/*
		if (rota >= rotb)
			rotate_list(&a->list, &b->list, rotb, 2);
			rotate_list(&a->list, &b->list, rota - rotb, 1);
		else
			rotate_list(&a->list, &b->list, rotb, 2);
			rotate_list(&a->list, &b->list, rota - rotb, 1);
*/
