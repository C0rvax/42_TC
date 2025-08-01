/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:27:07 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/19 13:11:38 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	check_wall(t_data *game)
{
	int	i;

	while (game->map[0][game->width])
		game->width++;
	if (!check_wall_line(game->map[0]))
		return (ft_error('w'), 0);
	while (game->map[++game->height])
	{
		i = 0;
		while (game->map[game->height][i])
			i++;
		if (i != game->width)
			return (ft_error('s'), 0);
		if (game->map[game->height][0] != '1' ||
			game->map[game->height][i - 1] != '1')
			return (ft_error('w'), 0);
	}
	if (!check_wall_line(game->map[game->height - 1]))
		return (ft_error('w'), 0);
	return (1);
}

int	check_map_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != 'M' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
