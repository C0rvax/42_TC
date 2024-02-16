/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:33:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/16 19:56:47 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	u_never_know(t_data *a)
{
	int		i;
	t_lst	*list;

	i = 0;
	list = a->list;
	while (i < a->size)
	{
		if (list->content < list->next->content)
			return (0);
		list = list->next;
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

static void	rotate_list(t_data *data, int i)
{
	if (i < 0)
	{
		i *= -1;
		while (i > 0)
		{
			exec_rotate(ft_printf("rra\n"), &data->list);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			exec_rotate(ft_printf("ra\n"), &data->list);
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
		rotate_list(a, i);
		exec_push(ft_printf("pa\n"), b, a);
	}
	i = find_content(a, a->min);
	rotate_list(a, i);
}

void	sort_list(t_data *a, t_data *b)
{
	if (u_never_know(a))
		return ;
	if (a->size == 3)
	{
		sort_3(a);
	}
	else if (a->size <= 5)
	{
		sort_5(a, b);
	}
	else
	{
//		sort_big(a, b);
	}
}
