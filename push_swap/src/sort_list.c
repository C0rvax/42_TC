/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:33:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/21 02:43:33 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	u_never_know(t_data *a)
{
	int		i;
	t_lst	*list;

	i = 0;
	list = a->list;
	while (i < a->size - 1)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

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
		exec_rotate(ft_printf("rra\n"), &data->list);
	}
	if (x > y && y < z && z < x)
		exec_rotate(ft_printf("ra\n"), &data->list);
	if (x < y && y > z && z > x)
	{
		exec_swap(ft_printf("sa\n"), data);
		exec_rotate(ft_printf("ra\n"), &data->list);
	}
	if (x < y && y > z && z < x)
		exec_rotate(ft_printf("rra\n"), &data->list);

}

void	rotate_list(t_lst **first, t_lst **sec, int i, int mode)
{
	if (i < 0)
	{
		i *= -1;
		while (i > 0)
		{
			if (mode == 2)
				exec_rotate(ft_printf("rrr\n"), sec);
			else if (mode == 3)
				ft_printf("rrb\n");
			else
				ft_printf("rra\n");
			exec_rotate(4 , first);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			if (mode == 2)
				exec_rotate(ft_printf("rr\n"), sec);
			else if (mode == 3)
				ft_printf("rb\n");
			else
				ft_printf("ra\n");		
			exec_rotate(3, first);
			i--;
		}
	}
}

void	rotate_list_mute(t_lst **first, t_lst **sec, int i, int mode)
{
	if (i < 0)
	{
		i *= -1;
		while (i > 0)
		{
			if (mode == 2)
				exec_rotate(4, sec);
			exec_rotate(4 , first);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			if (mode == 2)
				exec_rotate(3, sec);
			exec_rotate(3, first);
			i--;
		}
	}
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

	med = (a->max - a->min) / 2;
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
//	int	min;

	i = 0;
	set_list_max(a);
	push_in_b(a, b);
	sort_3(a);
	while (b->size)
	{
		all_in_a(a, b);
//		min = a->min;
		exec_push(ft_printf("pa\n"), b, a);
//		if (min != a->min)
//			rotate_list(&a->list, &b->list, -1, 1);
	}
	i = find_content(a, a->min);
	rotate_list(&a->list, &b->list, i, 1);
}
/*
static void	sort_5(t_data *a, t_data *b)
{
	int	first;
	int	sec;

	while (a->size > 3)
		exec_push(ft_printf("pb\n"), a, b);
	sort_3(a);
	while (b->size)
	{
		first = find_in_a(a, b->list->content);
		sec = find_in_a(a, b->list->next->content);
		rotate_list(a, i);
		exec_push(ft_printf("pa\n"), b, a);
	}
	i = find_content(a, a->min);
	rotate_list(a, i);
}
*/

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
