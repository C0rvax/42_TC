/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:36:56 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/13 12:23:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	char	*result;
	int		fd;

	result =malloc(sizeof(char) * 255);
	if (!result)
		return (1);
	fd = open("./test", O_RDONLY);
	get_next_line(fd, &result);
	return (0);
}
