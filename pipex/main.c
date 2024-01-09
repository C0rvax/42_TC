/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/09 17:02:00 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	if (ac < 5)
		return (ft_printf("Error\n"), 1);
	if (access(av[1], R_OK) != 0)
		return (perror("Error\n"), 1);
	if (access(av[ac - 1], W_OK) !=0)
		return (perror("Error\n"), 1);

}
