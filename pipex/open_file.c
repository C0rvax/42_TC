/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:19:50 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/18 17:35:56 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_data *data)
{
	data->fd[0] = open(data->av[1], O_RDONLY);
	if (data->fd[0] == -1)
		clean_exit(data, 'i');
	data->fd[1] = open(data->av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd[1] == -1)
		clean_exit(data, 'o');
}

void	close_file(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (data->fd[i] >= 0)
			close(data->fd[i]);
		if (data->pipefd[i] >= 0)
			close(data->pipefd[i]);
		i++;
	}
}
