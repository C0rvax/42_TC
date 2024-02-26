/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:33:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/24 20:31:01 by aduvilla         ###   ########.fr       */
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

static void	sort_500(t_data *a, t_data *b)
{
	int	i;

	i = 0;
	set_list_max(a);
	push_in_b(a, b);
	sort_3(a);
	while (b->size > 1)
	{
		all_in(a, b, 1);
		exec_push(ft_printf("pa\n"), b, a);
	}
	i = find_in_a(a, b->list->content);
	rotate_list(&a->list, NULL, i, 1);
	exec_push(ft_printf("pa\n"), b, a);
	i = find_content(a, a->min);
	rotate_list(&a->list, &b->list, i, 1);
}

static void	sort_100(t_data *a, t_data *b)
{
	int	i;
	int	min;

	i = 0;
	exec_push(ft_printf("pb\n"), a, b);
	exec_push(ft_printf("pb\n"), a, b);
	while (a->size > 3)
	{
		all_in(a, b, 2);
		min = b->min;
		exec_push(ft_printf("pb\n"), a, b);
		if (b->min != min && a->size > 4)
			rotate_list(&b->list, &a->list, 1, 3);
	}
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
	else if (a->size <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);
}
