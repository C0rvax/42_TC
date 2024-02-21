/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:44:22 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/21 17:46:20 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_rotate(int p, t_lst **list)
{
	if (p == 3)
		*list = (*list)->next;
	else
		*list = (*list)->prev;
	return (p);
}

static void	rotate_list_down(t_lst **first, t_lst **sec, int i, int mode)
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

static void	rotate_list_up(t_lst **first, t_lst **sec, int i, int mode)
{
	while (i > 0)
	{
		if (mode == 2)
			exec_rotate(ft_printf("rrr\n"), sec);
		else if (mode == 3)
			ft_printf("rrb\n");
		else
			ft_printf("rra\n");
		exec_rotate(4, first);
		i--;
	}
}

void	rotate_list(t_lst **first, t_lst **sec, int i, int mode)
{
	if (i < 0)
	{
		i *= -1;
		rotate_list_up(first, sec, i, mode);
	}
	else
		rotate_list_down(first, sec, i, mode);
}
