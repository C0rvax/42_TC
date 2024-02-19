/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:37:35 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/19 12:18:01 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_a_directory(char *ber)
{
	int	fd;

	fd = open(ber, O_DIRECTORY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	is_no_empty_line(char *line)
{
	int	i;

	i = 0;
	if (line && line[0] == '\n')
		return (1);
	while (line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}
