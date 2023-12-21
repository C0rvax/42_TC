/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:53:19 by aduvilla          #+#    #+#             */
/*   Updated: 2023/12/21 13:34:48 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_test(char **map, int x, int y)
{
	ft_printf("start");
	if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E')
	{
		map[y][x] = '1';
		ft_printf("in");
		flood_test(map, x - 1, y);
		flood_test(map, x + 1, y);
		flood_test(map, x, y - 1);
		flood_test(map, x, y + 1);
	}
}

int	check_tiles(t_data *game, int p, int e)
{
	int	x;
	int	y;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == game->sign.player)
			{
				p++;
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == game->sign.exit)
			//if (game->map[y][x] == 'E')
				e++;
			if (game->map[y][x] == game->sign.chicken)
				game->chicks++;
			x++;
		}
		y++;
	}
	ft_printf("ca arrive a la");
	ft_printf("e : %d p : %d", e, p);
	if (!check_tile_number(game, p, e))
		return (0);
	ft_printf("ca arrive a la fin de check_tiles");
	return (1);
}

int	check_tile_number(t_data *game, int p, int e)
{
	if (e != 1)
		return (0);
	if (p != 1)
		return (0);
	if (game->chicks < 1)
		return (0);
	return (1);
}
int	check_wall(t_data *game)
{
	if (game->map)
		return (1);
	return (0);
}

int	check_map(t_data *game)
{
	char	**copy;
	int	x;
	int y;

	copy = game->map;
	if (!check_wall(game))
		return (0);
	if (!check_tiles(game, 0, 0))
		return (0);
	flood_test(copy, game->player_x, game->player_y);
	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == game->sign.exit)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
