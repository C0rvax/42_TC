/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:24:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/09 17:40:40 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_swap(int p, int *stack)
{
	int	buf;

	buf = stack[0];
	stack[0] = stack[1];
	stack[1] = buf;
	return (p);
}
/*
void	exec_push(t_stack *take, t_stack *push)
{
}
*/
int	exec_rotate(int p, int *stack, int size)
{
	int	i;
	int	buf;

	i = 0;
	buf = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = buf;
	return (p);
}

int	exec_reverse(int p,int *stack, int size)
{
	int	i;
	int	buf;

	i = size - 1;
	buf = stack[i];
	while (i)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = buf;
	return (p);
}
