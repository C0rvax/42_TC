/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:19:50 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/15 17:49:08 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_data *data)
{
	data->fd = malloc(sizeof(int) * 2);
	data->fd[0] = open(data->av[1], O_RDONLY);
	if (data->fd[0] == -1)
		clean_exit(data);
	data->fd[1] = open(data->av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd[1] == -1)
		clean_exit(data);
}

void	close_file(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		ft_printf("fd av : %d\n", data->fd[i]);
		close(data->fd[i]);
		ft_printf("fd ap : %d\n", data->fd[i]);
		ft_printf("pi av : %i\n", data->pipefd[i]);
		close(data->pipefd[i]);
		ft_printf("pi ap : %i\n", data->pipefd[i]);
		i++;
	}
}
