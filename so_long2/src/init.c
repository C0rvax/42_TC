/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:20:59 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/21 20:23:27 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_data *game)
{
	game->sprite.height = 32;
	game->sprite.width = 32;
	game->sprite.floor = mlx_xpm_file_to_image(game->init,
			"./textures/floor.xpm", &game->sprite.width, &game->sprite.height);
	game->sprite.wall = mlx_xpm_file_to_image(game->init, "./textures/wall.xpm",
			&game->sprite.width, &game->sprite.height);
	game->sprite.chicken = mlx_xpm_file_to_image(game->init,
			"./textures/chicken.xpm", &game->sprite.width,
			&game->sprite.height);
	game->sprite.player = mlx_xpm_file_to_image(game->init,
			"./textures/player.xpm", &game->sprite.width, &game->sprite.height);
	game->sprite.exit = mlx_xpm_file_to_image(game->init, "./textures/exit.xpm",
			&game->sprite.width, &game->sprite.height);
	game->sprite.ennemy = mlx_xpm_file_to_image(game->init,
			"./textures/ennemy.xpm", &game->sprite.width, &game->sprite.height);
}

void	init_frame(t_data *game)
{
	game->frame.ul = mlx_xpm_file_to_image(game->init, "./textures/frameul.xpm",
			&game->sprite.width, &game->sprite.height);
	game->frame.u = mlx_xpm_file_to_image(game->init, "./textures/frameu.xpm",
			&game->sprite.width, &game->sprite.height);
	game->frame.ur = mlx_xpm_file_to_image(game->init, "./textures/frameur.xpm",
			&game->sprite.width, &game->sprite.height);
	game->frame.l = mlx_xpm_file_to_image(game->init, "./textures/framel.xpm",
			&game->sprite.width, &game->sprite.height);
	game->frame.r = mlx_xpm_file_to_image(game->init, "./textures/framer.xpm",
			&game->sprite.width, &game->sprite.height);
	game->frame.dl = mlx_xpm_file_to_image(game->init, "./textures/framedl.xpm",
			&game->sprite.width, &game->sprite.height);
	game->frame.d = mlx_xpm_file_to_image(game->init, "./textures/framed.xpm",
			&game->sprite.width, &game->sprite.height);
	game->frame.dr = mlx_xpm_file_to_image(game->init, "./textures/framedr.xpm",
			&game->sprite.width, &game->sprite.height);
}

static void	init_game(t_data *game)
{
	game->init = mlx_init();
	if (!game->init)
		return (ft_freetab(game->map));
	init_sprite(game);
	init_frame(game);
}

static char	**init_map(char *ber, t_data *game)
{
	char	*line;

	line = get_all_lines(ber);
	if (!line)
		return (perror("Error"), NULL);
	game->map = ft_split(line, '\n');
	free(line);
	if (!game->map)
		return (perror("Error"), NULL);
	if (!check_map(game))
		return (NULL);
	return (game->map);
}

int	init_struct(t_data *game, char *title)
{
	game->init = NULL;
	game->window = NULL;
	game->map = NULL;
	game->turns = 0;
	game->chicks = 0;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->map = init_map(title, game);
	if (!game->map)
		return (1);
	init_game(game);
	return (0);
}
