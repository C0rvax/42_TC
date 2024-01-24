/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:17:48 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/22 14:37:01 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_sprite(t_data *game)
{
	if (game->sprite.wall)
		mlx_destroy_image(game->init, game->sprite.wall);
	if (game->sprite.floor)
		mlx_destroy_image(game->init, game->sprite.floor);
	if (game->sprite.chicken)
		mlx_destroy_image(game->init, game->sprite.chicken);
	if (game->sprite.player)
		mlx_destroy_image(game->init, game->sprite.player);
	if (game->sprite.exit)
		mlx_destroy_image(game->init, game->sprite.exit);
	if (game->sprite.ennemy)
		mlx_destroy_image(game->init, game->sprite.ennemy);
}

static void	free_frame(t_data *game)
{
	if (game->frame.ul)
		mlx_destroy_image(game->init, game->frame.ul);
	if (game->frame.ur)
		mlx_destroy_image(game->init, game->frame.ur);
	if (game->frame.u)
		mlx_destroy_image(game->init, game->frame.u);
	if (game->frame.l)
		mlx_destroy_image(game->init, game->frame.l);
	if (game->frame.r)
		mlx_destroy_image(game->init, game->frame.r);
	if (game->frame.dl)
		mlx_destroy_image(game->init, game->frame.dl);
	if (game->frame.dr)
		mlx_destroy_image(game->init, game->frame.dr);
	if (game->frame.d)
		mlx_destroy_image(game->init, game->frame.d);
}

int	end_game(t_data *game)
{
	if (game->map)
		ft_freetab(game->map);
	free_sprite(game);
	free_frame(game);
	if (game->window)
		mlx_destroy_window(game->init, game->window);
	if (game->init)
	{
		mlx_destroy_display(game->init);
		free(game->init);
	}
	exit(0);
}

void	game_over(t_data *game)
{
	ft_printf("\n      GAME OVER\n");
	end_game(game);
}
