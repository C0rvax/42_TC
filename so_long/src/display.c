/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:37:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/24 18:44:38 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_sprite(t_data *game, void *sprite, int x, int y)
{
	int	width;
	int	height;

	width = game->w_img * x;
	height = game->h_img * y;
	mlx_put_image_to_window(game->init, game->window, sprite, width, height);
}

static void	display_frame(t_data *game, int x, int y)
{
	int	xmax;

	xmax = x;
	display_sprite(game, game->frame.ul, 0, 0);
	display_sprite(game, game->frame.ur, x, 0);
	display_sprite(game, game->frame.dl, 0, y);
	display_sprite(game, game->frame.dr, x, y);
	while (x-- > 1)
	{
		display_sprite(game, game->frame.u, x, 0);
		display_sprite(game, game->frame.d, x, y);
	}
	while (y-- > 1)
	{
		display_sprite(game, game->frame.l, 0, y);
		display_sprite(game, game->frame.r, xmax, y);
	}
}

static void	display_center(int x, int y, t_data *game)
{
	if (game->map[y][x] == '0')
		display_sprite(game, game->sprite.floor, x, y);
	if (game->map[y][x] == 'C')
		display_sprite(game, game->sprite.chicken, x, y);
	if (game->map[y][x] == 'P')
		display_sprite(game, game->sprite.player, x, y);
	if (game->map[y][x] == 'E')
		display_sprite(game, game->sprite.exit, x, y);
	if (game->map[y][x] == '1')
		display_sprite(game, game->sprite.wall, x, y);
	if (game->map[y][x] == 'M')
		display_sprite(game, game->sprite.ennemy, x, y);
}

int	display(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[++y + 1])
	{
		x = 0;
		while (game->map[y + 1][++x + 1])
		{
			display_center(x, y, game);
		}
	}
	display_frame(game, x, y);
	return (0);
}
