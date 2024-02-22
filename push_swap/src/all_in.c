/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:03:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/23 00:07:23 by aduvilla         ###   ########.fr       */
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

static void	check_cost(t_data *a, t_data *b, int *cost)
{
	int		i;
	int		j;
	t_lst	*lst;

	lst = b->list;
	i = -1;
	while (++i < b->size / 2)
		lst = lst->prev;
	i = -(b->size / 2);
	while (i < ((b->size / 2) + 1))
	{
		j = find_in_a(a, lst->content);
		if (cost_max_min(i, j) < cost[0])
		{
			cost[1] = i;
			cost[2] = j;
			cost[0] = cost_max_min(i, j);
		}
		i++;
		lst = lst->next;
	}
}

void	all_in_a(t_data *a, t_data *b)
{
	int	*cost;

	cost = malloc(sizeof(int) * 3);
	cost[0] = a->size + b->size ;
	check_cost(a, b, cost);
	if ((cost[2] >= 0 && cost[1] < 0) || (cost[2] < 0 && cost[1] >= 0))
	{
		rotate_list(&a->list, &b->list, cost[2], 1);
		rotate_list(&b->list, &a->list, cost[1], 3);
	}
	else
	{
		cost[0] = get_max_min(cost[1], cost[2]);
		rotate_list(&a->list, &b->list, cost[0], 2);
		if (cost[0] == cost[1])
			rotate_list(&a->list, &b->list, cost[2] - cost[0], 1);
		else
			rotate_list(&b->list, &b->list, cost[1] - cost[0], 3);
	}
	free (cost);
}

void	all_in_b(t_data *a, t_data *b)
{
	int	*cost;

	cost = malloc(sizeof(int) * 3);
	cost[0] = a->size + b->size ;
	check_cost(a, b, cost);
	if ((cost[2] >= 0 && cost[1] < 0) || (cost[2] < 0 && cost[1] >= 0))
	{
		rotate_list(&a->list, &b->list, cost[2], 1);
		rotate_list(&b->list, &a->list, cost[1], 3);
	}
	else
	{
		cost[0] = get_max_min(cost[1], cost[2]);
		rotate_list(&a->list, &b->list, cost[0], 2);
		if (cost[0] == cost[1])
			rotate_list(&a->list, &b->list, cost[2] - cost[0], 1);
		else
			rotate_list(&b->list, &b->list, cost[1] - cost[0], 3);
	}
	free (cost);
}
