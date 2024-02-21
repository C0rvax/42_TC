/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:33:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/21 17:53:59 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_data *data)
{
	int	x;
	int	y;
	int	z;

	x = data->list->content;
	y = data->list->next->content;
	z = data->list->prev->content;
	if (x > y && y < z && z > x)
		exec_swap(ft_printf("sa\n"), data);
	if (x > y && y > z && z < x)
	{
		exec_swap(ft_printf("sa\n"), data);
		rotate_list(&data->list, NULL, -1, 1);
	}
	if (x > y && y < z && z < x)
		rotate_list(&data->list, NULL, 1, 1);
	if (x < y && y > z && z > x)
	{
		exec_swap(ft_printf("sa\n"), data);
		rotate_list(&data->list, NULL, 1, 1);
	}
	if (x < y && y > z && z < x)
		rotate_list(&data->list, NULL, -1, 1);
}

static void	sort_5(t_data *a, t_data *b)
{
	int	i;

	i = 0;
	while (a->size > 3)
		exec_push(ft_printf("pb\n"), a, b);
	sort_3(a);
	while (b->size)
	{
		i = find_in_a(a, b->list->content);
		rotate_list(&a->list, &b->list, i, 1);
		exec_push(ft_printf("pa\n"), b, a);
	}
	i = find_content(a, a->min);
	rotate_list(&a->list, &b->list, i, 1);
}

static void	push_in_b(t_data *a, t_data *b)
{
	int	med;
	int	val;

	med = get_med(a, a->min, a->max);
	while (a->size > 3)
	{
		val = a->list->content;
		exec_push(ft_printf("pb\n"), a, b);
		if (val >= med && b->size > 1)
			rotate_list(&b->list, &a->list, 1, 3);
	}
}

static void	sort_big(t_data *a, t_data *b)
{
	int	i;

	i = 0;
	set_list_max(a);
	push_in_b(a, b);
	sort_3(a);
	while (b->size)
	{
		all_in_a(a, b);
		exec_push(ft_printf("pa\n"), b, a);
	}
	i = find_content(a, a->min);
	rotate_list(&a->list, &b->list, i, 1);
}

void	sort_list(t_data *a, t_data *b)
{
	if (u_never_know(a))
		return ;
	else if (a->size == 2)
		rotate_list(&a->list, &b->list, 1, 1);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		sort_big(a, b);
}
