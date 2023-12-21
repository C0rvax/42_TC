/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:38:47 by aduvilla          #+#    #+#             */
/*   Updated: 2023/12/21 17:39:28 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char c)
{
	if (c == 'w')
		ft_printf("Error\nInvalid map : not surrounded by walls !");
	if (c == 'f')
		ft_printf("Error\nInvalid map : no path to exit !");
	if (c == 'e')
		ft_printf("Error\nInvalid map : need 1 exit !");
	if (c == 'p')
		ft_printf("Error\nInvalid map : need 1 player !");
	if (c == 'c')
		ft_printf("Error\nInvalid map : need minimum 1 chicken !");
	if (c == 's')
		ft_printf("Error\nInvalid map : not rectangular !");
}
