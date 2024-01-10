/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:38:21 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/10 16:33:05 by aduvilla         ###   ########.fr       */
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

int	check_ext(char *file, char *ext)
{
	int	f;
	int	e;

	if (!file || !ext)
		return (0);
	f = ft_strlen(file) - 1;
	e = ft_strlen(ext) - 1;
	while (e >= 0)
	{
		if (file[f] != ext[e])
			return (0);
		e--;
		f--;
	}
	return (1);
}
