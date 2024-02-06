/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:19:50 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/20 20:16:18 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_data *data)
{
	char	*outfile;

	outfile = data->av[data->cmd_max + 2];
	data->fd[0] = open(data->av[1], O_RDONLY);
	if (data->fd[0] == -1)
		clean_exit(data, 'i');
	data->fd[1] = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
		i++;
	}
	i = 0;
	while (i < data->cmd_max - 1)
	{
		if (data->pipefd[i][0] >= 0)
			close(data->pipefd[i][0]);
		if (data->pipefd[i][1] >= 0)
			close(data->pipefd[i][1]);
		i++;
	}
}
