/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:53:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:32 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_test(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'C')
	{
		map[y][x] = 'X';
		flood_test(map, x - 1, y);
		flood_test(map, x + 1, y);
		flood_test(map, x, y - 1);
		flood_test(map, x, y + 1);
	}
	if (map[y][x] == 'E')
		map[y][x] = '2';
}

static int	check_tile_number(t_data *game, int p, int e)
{
	if (e != 1)
		return (ft_error('e'), 0);
	if (p != 1)
		return (ft_error('p'), 0);
	if (game->chicks < 1)
		return (ft_error('c'), 0);
	return (1);
}

static int	check_tiles(t_data *game, int p, int e)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				p++;
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'E')
				e++;
			if (game->map[y][x] == 'C')
				game->chicks++;
		}
	}
	if (!check_tile_number(game, p, e))
		return (0);
	return (1);
}

static int	check_map(t_data *game)
{
	char	**copy;
	int		x;
	int		y;

	copy = tab_dup(game->map);
	if (!copy)
		return (perror("Error"), ft_freetab(game->map), 0);
	if (!check_wall(game))
		return (ft_freetab(game->map), ft_freetab(copy), 0);
	if (!check_tiles(game, 0, 0))
		return (ft_freetab(game->map), ft_freetab(copy), 0);
	flood_test(copy, game->player_x, game->player_y);
	y = -1;
	while (copy[++y])
	{
		x = -1;
		while (copy[y][++x])
		{
			if (copy[y][x] == 'E' || copy[y][x] == 'C')
				return (ft_error('f'), ft_freetab(game->map),
					ft_freetab(copy), 0);
		}
	}
	ft_freetab(copy);
	return (1);
}

char	**init_map(char *ber, t_data *game)
{
	char	*line;

	line = get_all_lines(ber);
	if (!line)
		return (perror("Error"), NULL);
	if (ft_strncmp(line, "", 1) == 0)
		return (ft_error('m'), NULL);
	game->map = ft_split(line, '\n');
	if (!game->map)
		return (free(line), perror("Error"), NULL);
	if (check_map_char(line, game->map))
		return (free(line), ft_freetab(game->map), NULL);
	free(line);
	if (!check_map(game))
		return (NULL);
	return (game->map);
}
