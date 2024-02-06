/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:03:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 19:26:11 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	int	*a;

	if (ac < 2)
		return (0);
	a = check_list(av, ac);
	if (!a)
		return (1);
	i = 0;
	while (i < ac - 1)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	return (0);
}
