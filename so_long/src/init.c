/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:20:59 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/17 23:15:43 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_data *game)
{
	game->init = NULL;
	game->window = NULL;
	game->map = NULL;
	game->turns = 0;
	game->chicks = 0;
	game->width = 0;
	game->height = 0;
	game->w_img = 32;
	game->h_img = 32;
	game->player_x = 0;
	game->player_y = 0;
	game->sprite.floor = NULL;
	game->sprite.wall = NULL;
	game->sprite.chicken = NULL;
	game->sprite.player = NULL;
	game->sprite.exit = NULL;
	game->sprite.ennemy = NULL;
	game->frame.ul = NULL;
	game->frame.u = NULL;
	game->frame.ur = NULL;
	game->frame.l = NULL;
	game->frame.r = NULL;
	game->frame.dl = NULL;
	game->frame.d = NULL;
	game->frame.dr = NULL;
}

static void	init_sprite(t_data *game)
{
	game->sprite.floor = mlx_xpm_file_to_image(game->init,
			"./textures/floor.xpm", &game->w_img, &game->h_img);
	if (!game->sprite.floor)
		end_game(game);
	game->sprite.wall = mlx_xpm_file_to_image(game->init,
			"./textures/wall.xpm", &game->w_img, &game->h_img);
	if (!game->sprite.wall)
		end_game(game);
	game->sprite.chicken = mlx_xpm_file_to_image(game->init,
			"./textures/chicken.xpm", &game->w_img, &game->h_img);
	if (!game->sprite.chicken)
		end_game(game);
	game->sprite.player = mlx_xpm_file_to_image(game->init,
			"./textures/player.xpm", &game->w_img, &game->h_img);
	if (!game->sprite.player)
		end_game(game);
	game->sprite.exit = mlx_xpm_file_to_image(game->init,
			"./textures/exit.xpm", &game->w_img, &game->h_img);
	if (!game->sprite.exit)
		end_game(game);
	game->sprite.ennemy = mlx_xpm_file_to_image(game->init,
			"./textures/ennemy.xpm", &game->w_img, &game->h_img);
	if (!game->sprite.ennemy)
		end_game(game);
}

static void	init_frame1(t_data *game)
{
	game->frame.ul = mlx_xpm_file_to_image(game->init,
			"./textures/frameul.xpm", &game->w_img, &game->h_img);
	if (!game->frame.ul)
		end_game(game);
	game->frame.u = mlx_xpm_file_to_image(game->init,
			"./textures/frameu.xpm", &game->w_img, &game->h_img);
	if (!game->frame.u)
		end_game(game);
	game->frame.ur = mlx_xpm_file_to_image(game->init,
			"./textures/frameur.xpm", &game->w_img, &game->h_img);
	if (!game->frame.ur)
		end_game(game);
	game->frame.l = mlx_xpm_file_to_image(game->init,
			"./textures/framel.xpm", &game->w_img, &game->h_img);
	if (!game->frame.l)
		end_game(game);
}

static void	init_frame2(t_data *game)
{
	game->frame.r = mlx_xpm_file_to_image(game->init,
			"./textures/framer.xpm", &game->w_img, &game->h_img);
	if (!game->frame.r)
		end_game(game);
	game->frame.dl = mlx_xpm_file_to_image(game->init,
			"./textures/framedl.xpm", &game->w_img, &game->h_img);
	if (!game->frame.dl)
		end_game(game);
	game->frame.d = mlx_xpm_file_to_image(game->init,
			"./textures/framed.xpm", &game->w_img, &game->h_img);
	if (!game->frame.d)
		end_game(game);
	game->frame.dr = mlx_xpm_file_to_image(game->init,
			"./textures/framedr.xpm", &game->w_img, &game->h_img);
	if (!game->frame.dr)
		end_game(game);
}

int	init_game(char *map, t_data *game)
{
	ft_bzero(game, sizeof(t_data));
	init_struct(game);
	game->map = init_map(map, game);
	if (!game->map)
		return (1);
	game->init = mlx_init();
	if (!game->init)
		return (ft_freetab(game->map), 1);
	init_sprite(game);
	init_frame1(game);
	init_frame2(game);
	return (0);
}
