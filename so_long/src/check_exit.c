/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:38:21 by aduvilla          #+#    #+#             */
/*   Updated: 2023/12/21 17:38:25 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_chicks(t_data *game)
{
	game->chicks--;
}

void	check_exit(t_data *game)
{
	if (game->chicks == 0)
	{
		game->turns++;
		ft_printf("\nYou Win !!!\nTurns : %d\n", game->turns);
		end_game(game);
	}
}
