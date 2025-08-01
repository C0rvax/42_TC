/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:35:00 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/18 02:23:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char c)
{
	if (c == 'w')
		ft_putstr_fd("Error\nInvalid map: not surrounded by walls !\n", 2);
	if (c == 'f')
		ft_putstr_fd("Error\nInvalid map: no path to exit!\n", 2);
	if (c == 'e')
		ft_putstr_fd("Error\nInvalid map: need 1 exit!\n", 2);
	if (c == 'p')
		ft_putstr_fd("Error\nInvalid map: need 1 player!\n", 2);
	if (c == 'c')
		ft_putstr_fd("Error\nInvalid map: need minimum 1 chicken!\n", 2);
	if (c == 's')
		ft_putstr_fd("Error\nInvalid map: invalid shape!\n", 2);
	if (c == 'l')
		ft_putstr_fd("Error\nInvalid map: use only: 1 0 P E M C \n", 2);
	if (c == 'a')
		ft_putstr_fd("Error\nThis program need 1 argument!\n", 2);
	if (c == 'b')
		ft_putstr_fd("Error\nArgument: Need a .ber extension!\n", 2);
	if (c == 'm')
		ft_putstr_fd("Error\nInvalid map: The map is empty!\n", 2);
	if (c == 'd')
		ft_putstr_fd("Error\nInvalid map: Map path is a directory!\n", 2);
}

char	**tab_dup(char **tab)
{
	int		i;
	char	**res;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
			return (ft_freetab(res), NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	*get_all_lines(char *ber)
{
	int		fd;
	char	*buf;
	char	*line;
	char	*copy;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		copy = line;
		line = ft_strjoin(line, buf);
		if (!line)
			return (close(fd), free(buf), free(copy), NULL);
		free(copy);
		free(buf);
	}
	close(fd);
	return (line);
}

void	check_exit(t_data *game)
{
	if (game->chicks == 0)
	{
		game->turns++;
		ft_printf("\n        You Win !!!\nTurns : %d\n", game->turns);
		end_game(game);
	}
}

int	check_ext(char *file, char *ext)
{
	int	f;
	int	e;

	if (!file || !ext)
		return (0);
	f = ft_strlen(file) - 1;
	e = ft_strlen(ext) - 1;
	while (e >= 0)
	{
		if (file[f] != ext[e])
			return (0);
		e--;
		f--;
	}
	return (1);
}
