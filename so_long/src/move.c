/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:35:41 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/03 16:19:20 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key(int keysym, t_data *game)
{
	if (keysym == XK_Escape)
		end_game(game);
	if (keysym == XK_w)
		move_top(game);
	if (keysym == XK_s)
		move_down(game);
	if (keysym == XK_a)
		move_left(game);
	if (keysym == XK_d)
		move_right(game);
	return (0);
}

void	move_top(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != game->sign.wall)
	{
		if (game->map[y - 1][x] == game->sign.chicken)
			add_chicks(game);
		if (game->map[y - 1][x] == game->sign.ennemy)
			game_over(game);
		if (game->map[y - 1][x] != game->sign.exit)
		{
			game->map[y - 1][x] = game->sign.player;
			game->map[y][x] = game->sign.floor;
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_y--;
		}
		if (game->map[y - 1][x] == game->sign.exit)
			check_exit(game);
	}
}

void	move_down(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] != game->sign.wall)
	{
		if (game->map[y + 1][x] == game->sign.chicken)
			add_chicks(game);
		if (game->map[y + 1][x] == game->sign.ennemy)
			game_over(game);
		if (game->map[y + 1][x] != game->sign.exit)
		{
			game->map[y + 1][x] = game->sign.player;
			game->map[y][x] = game->sign.floor;
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_y++;
		}
		if (game->map[y + 1][x] == game->sign.exit)
			check_exit(game);
	}
}

void	move_left(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != game->sign.wall)
	{
		if (game->map[y][x - 1] == game->sign.chicken)
			add_chicks(game);
		if (game->map[y][x - 1] == game->sign.ennemy)
			game_over(game);
		if (game->map[y][x - 1] != game->sign.exit)
		{
			game->map[y][x - 1] = game->sign.player;
			game->map[y][x] = game->sign.floor;
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_x--;
		}
		if (game->map[y][x - 1] == game->sign.exit)
			check_exit(game);
	}
}

void	move_right(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != game->sign.wall)
	{
		if (game->map[y][x + 1] == game->sign.chicken)
			add_chicks(game);
		if (game->map[y][x + 1] == game->sign.ennemy)
			game_over(game);
		if (game->map[y][x + 1] != game->sign.exit)
		{
			game->map[y][x + 1] = game->sign.player;
			game->map[y][x] = game->sign.floor;
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_x++;
		}
		if (game->map[y][x + 1] == game->sign.exit)
			check_exit(game);
	}
}
