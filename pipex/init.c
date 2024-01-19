/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:31:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/19 13:41:56 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_malloc(t_data *data)
{
	data->fd = malloc(sizeof(int) * 2);
	if (!data->fd)
		clean_exit(data, 'm');
	data->fd[0] = -2;
	data->fd[1] = -2;
	data->pipefd = malloc(sizeof(int) * 2);
	if (!data->pipefd)
		clean_exit(data, 'm');
	data->pipefd[0] = -2;
	data->pipefd[1] = -2;
	data->pid = malloc(sizeof(int) * 2);
	if (!data->pid)
		clean_exit(data, 'm');
	data->pid[0] = -2;
	data->pid[1] = -2;
}

static void	init_pipe(t_data *data)
{
	int	p;

	p = pipe(data->pipefd);
	if (p == -1)
		clean_exit(data, 'p');
}

void	init_argv(t_data *data)
{
	get_paths(data);
	if (!data->paths)
		clean_exit(data, 'm');
	data->argv = ft_split(data->av[data->cmd_n + 2], ' ');
	if (!data->argv)
	{
		ft_freetab(data->paths);
		clean_exit(data, 'm');
	}
	data->cmd = get_cmd(data->argv[0], data);
	if (!data->cmd)
	{
		ft_freetab(data->paths);
		free(data->cmd);
		clean_exit(data, 'c');
	}
	ft_freetab(data->paths);
}

t_data	init_struct(char **av, char **env)
{
	t_data	data;

	data.av = av;
	data.env = env;
	init_malloc(&data);
	open_file(&data);
	init_pipe(&data);
	return (data);
}
