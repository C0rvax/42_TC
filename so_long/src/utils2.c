/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:37:35 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/16 16:42:03 by aduvilla         ###   ########.fr       */
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
