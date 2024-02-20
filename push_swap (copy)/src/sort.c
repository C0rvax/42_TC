/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:54:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/09 11:44:48 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(int *stack)
{
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[2] > stack[0])
		exec_swap(ft_printf("sa\n"), stack);
	if (stack[0] > stack[1] && stack[1] > stack[2] && stack[2] < stack[0])
	{
		exec_swap(ft_printf("sa\n"), stack);
		exec_reverse(ft_printf("rra\n"), stack, 3);
	}
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[2] < stack[0])
		exec_rotate(ft_printf("ra\n"), stack, 3);
	if (stack[0] < stack[1] && stack[1] > stack[2] && stack[2] > stack[0])
	{
		exec_swap(ft_printf("sa\n"), stack);
		exec_rotate(ft_printf("ra\n"), stack, 3);
	}
	if (stack[0] < stack[1] && stack[1] > stack[2] && stack[2] < stack[0])
		exec_reverse(ft_printf("rra\n"), stack, 3);
}
