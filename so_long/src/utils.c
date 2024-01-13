/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:35:00 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/04 09:12:44 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**tab_dup(char **tab)
{
	int		i;
	char	**res;

	i = 0;
	while (tab[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		res[i] = ft_strdup(tab[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
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
			return (free(buf), free(copy), NULL);
		free(copy);
		free(buf);
	}
	close(fd);
	return (line);
}
