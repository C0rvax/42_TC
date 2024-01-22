/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:37:48 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/22 14:32:14 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	main_loop(t_data *game, char *title)
{
	int	x;
	int	y;

	x = game->width * game->w_img;
	y = game->height * game->h_img;
	game->window = mlx_new_window(game->init, x, y, title);
	if (!game->window)
		return (ft_freetab(game->map), mlx_destroy_display(game->init),
			free(game->init));
	mlx_loop_hook(game->init, &display, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &input_key, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, &end_game, game);
	mlx_loop(game->init);
	end_game(game);
}

int	main(int ac, char **ag)
{
	t_data	game;

	if (ac != 2)
		return (ft_error('a'), 1);
	if (!check_ext(ag[1], ".ber"))
		return (ft_error('b'), 1);
	if (init_game(ag[1], &game))
		return (1);
	main_loop(&game, ag[0]);
	return (0);
}
