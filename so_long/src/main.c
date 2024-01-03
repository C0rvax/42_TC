/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:37:48 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/03 16:21:10 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_data *game)
{
	mlx_destroy_image(game->init, game->sprite.wall);
	mlx_destroy_image(game->init, game->sprite.floor);
	mlx_destroy_image(game->init, game->sprite.chicken);
	mlx_destroy_image(game->init, game->sprite.player);
	mlx_destroy_image(game->init, game->sprite.exit);
	mlx_destroy_image(game->init, game->sprite.ennemy);
	mlx_destroy_image(game->init, game->frame.ul);
	mlx_destroy_image(game->init, game->frame.ur);
	mlx_destroy_image(game->init, game->frame.u);
	mlx_destroy_image(game->init, game->frame.l);
	mlx_destroy_image(game->init, game->frame.r);
	mlx_destroy_image(game->init, game->frame.dl);
	mlx_destroy_image(game->init, game->frame.dr);
	mlx_destroy_image(game->init, game->frame.d);
}

int	end_game(t_data *game)
{
	if (game->map)
		ft_free_tab(game->map);
	free_image(game);
	mlx_destroy_window(game->init, game->window);
	mlx_destroy_display(game->init);
	free(game->init);
	ft_printf("Quit succesfull\n");
	exit(0);
}

void	game_over(t_data *game)
{
	ft_printf("\n      GAME OVER\n");
	end_game(game);
}

void	main_loop(t_data *game, char *title)
{
	int	x;
	int	y;

	x = game->width * game->sprite.width;
	y = game->height * game->sprite.height;
	game->window = mlx_new_window(game->init, x, y, title);
	if (!game->window)
		return (ft_free_tab(game->map), free(game->init));
	display_back(game);
	mlx_loop_hook(game->init, &display, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &input_key, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, &end_game, game);
	mlx_loop(game->init);
	end_game(game);
}
//	mlx_key_hook(game->window, &input_key, game);
//	mlx_hook(game->window, KeyRelease, KeyReleaseMask, &input_key, game);

int	main(int ac, char **ag)
{
	t_data	game;

	if (ac != 2)
	{
		ft_printf("Error\nSo_long need a .ber as argument !\n");
		return (1);
	}
	init_sign(&game);
	game.map = init_map(ag[1], &game);
	if (!game.map)
		return (1);
	initialize_game(&game);
	main_loop(&game, ag[0]);
	return (0);
}
