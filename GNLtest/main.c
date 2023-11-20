/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:36:56 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/20 13:07:41 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*copy;

	fd = open("./bible.txt", O_RDONLY);
	while (1)
	{
		copy = get_next_line(fd);
		printf("copy : %s\n", copy);
		if (!copy)
			break ;
		free(copy);
	}
	// fd = open("./test", O_RDONLY);
	// printf("1er gnl : %s\n", get_next_line(fd));
	// printf("2er gnl : %s\n", get_next_line(fd));
	// printf("3er gnl : %s\n", get_next_line(fd));
	// printf("4er gnl : %s\n", get_next_line(fd));
	// printf("5er gnl : %s\n", get_next_line(fd));
	// printf("6er gnl : %s\n", get_next_line(fd));
	// printf("7er gnl : %s\n", get_next_line(fd));
	// printf("8er gnl : %s\n", get_next_line(fd));
	// fd = open("./nonl", O_RDONLY);
	// printf("1er gnl : %s\n", get_next_line(fd));
	// printf("2er gnl : %s\n", get_next_line(fd));
	// printf("1er gnl : %s\n", get_next_line(fd));
	// printf("2er gnl : %s\n", get_next_line(fd));
	// fd = open("./longligne", O_RDONLY);
	// printf("1er dde long : %s\n", get_next_line(fd));
	// //fd = open("./nonl", O_RDONLY);
	// //printf("1er gnl : %s\n", gnl(fd));
	return (0);
}
