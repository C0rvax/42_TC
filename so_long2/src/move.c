/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:35:41 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/21 19:38:40 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_top(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			game->chicks--;
		if (game->map[y - 1][x] == 'M')
			game_over(game);
		if (game->map[y - 1][x] != 'E')
		{
			game->map[y - 1][x] = 'P';
			game->map[y][x] = '0';
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_y--;
		}
		if (game->map[y - 1][x] == 'E')
			check_exit(game);
	}
}

static void	move_down(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			game->chicks--;
		if (game->map[y + 1][x] == 'M')
			game_over(game);
		if (game->map[y + 1][x] != 'E')
		{
			game->map[y + 1][x] = 'P';
			game->map[y][x] = '0';
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_y++;
		}
		if (game->map[y + 1][x] == 'E')
			check_exit(game);
	}
}

static void	move_left(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			game->chicks--;
		if (game->map[y][x - 1] == 'M')
			game_over(game);
		if (game->map[y][x - 1] != 'E')
		{
			game->map[y][x - 1] = 'P';
			game->map[y][x] = '0';
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_x--;
		}
		if (game->map[y][x - 1] == 'E')
			check_exit(game);
	}
}

static void	move_right(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			game->chicks--;
		if (game->map[y][x + 1] == 'M')
			game_over(game);
		if (game->map[y][x + 1] != 'E')
		{
			game->map[y][x + 1] = 'P';
			game->map[y][x] = '0';
			game->turns++;
			ft_printf("Turns : %d\n", game->turns);
			game->player_x++;
		}
		if (game->map[y][x + 1] == 'E')
			check_exit(game);
	}
}

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
