/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:36:56 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/13 09:47:36 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	char	*result;
	int		fd;

	fd = open(test, O_RDONLY);
	get_next_line(fd, &result);
	return (0);
}
