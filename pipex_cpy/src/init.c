/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:31:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/20 20:12:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_malloc(t_data *data)
{
	int	i;

	i = 0;
	data->fd = malloc(sizeof(int) * 2);
	if (!data->fd)
		clean_exit(data, 'm');
	data->fd[0] = -2;
	data->fd[1] = -2;
	data->pipefd = malloc(sizeof(int *) * (data->cmd_max - 1));
	if (!data->pipefd)
		clean_exit(data, 'm');
	while (i < data->cmd_max - 1)
	{
		data->pipefd[i] = malloc(sizeof(int) * 2);
		if (!data->pipefd[i])
			clean_exit(data, 'm');
		data->pipefd[i][0] = -2;
		data->pipefd[i][1] = -2;
		i++;
	}
	data->pid = malloc(sizeof(int) * data->cmd_max);
	if (!data->pid)
		clean_exit(data, 'm');
	data->pid[0] = -2;
	data->pid[1] = -2;
}

static void	init_pipe(t_data *data)
{
	int	p;
	int	i;

	i = 0;
	while (i < data->cmd_max - 1)
	{
		p = pipe(data->pipefd[i]);
		if (p == -1)
			clean_exit(data, 'p');
		i++;
	}
}

void	init_argv(t_data *data)
{
	data->argv = ft_split(data->av[data->cmd_n + 2], ' ');
	if (!data->argv)
		clean_exit(data, 'm');
	data->cmd = get_cmd(data->argv[0], data);
	if (!data->cmd)
	{
		ft_freetab(data->argv);
		clean_exit(data, 'c');
	}
}

t_data	init_struct(int ac, char **av, char **env)
{
	t_data	data;

	data.av = av;
	data.env = env;
	data.cmd_max = ac - 3;
	data.paths = NULL;
	data.argv = NULL;
	data.cmd = NULL;
	data.fd = NULL;
	data.pipefd = NULL;
	data.pid = NULL;
	get_paths(&data);
	if (!data.paths)
		clean_exit(&data, 'm');
	init_malloc(&data);
	open_file(&data);
	init_pipe(&data);
	return (data);
}
