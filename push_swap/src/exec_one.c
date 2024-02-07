/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:24:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/07 23:18:19 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_swap(t_stack *stack)
{
	int	buf;

	buf = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = buf;
}

void	exec_push(t_stack *take, t_stack *push)
{
}

void	exec_rotate(t_stack *stack)
{
	int	i;
	int	buf;

	i = 0;
	buf = stack->stack[0];
	while (i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = buf;
}

void	exec_reverse(t_stack *stack)
{
	int	i;
	int	buf;

	i = stack->size - 1;
	buf = stack->stack[i];
	while (i)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = buf;
}
