/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:31:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/19 20:46:52 by aduvilla         ###   ########.fr       */
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

static void	init_cmd(t_data *data)
{
	int i;
	char	**path;

	i = 0;
	path = get_paths(data->env);
	if (!path)
		clean_exit(data, 'm');
	data->cmd = malloc(sizeof(char *) * 3);
	if (!data->cmd)
	{
		ft_freetab(path);
		clean_exit(data, 'm');
	}
	i = 0;
	while (i < 2)
	{
		data->cmd[i] = get_cmd(data->argv[i][0], path);
		if (!data->cmd[i])
		{
			ft_freetab(path);
			clean_exit(data, 'c');
		}
		i++;
	}
	data->cmd[i] = NULL;
	ft_freetab(path);
}

static void	init_argv(t_data *data)
{
	int 	i;

	i = 0;
	data->argv = malloc(sizeof(char **) * 3);
	if (!data->argv)
		clean_exit(data, 'm');
	while (i < 2)
	{
		data->argv[i] = ft_split(data->av[i + 2], ' ');
		if (!data->argv[i])
			clean_exit(data, 'm');
		i++;
	}
	data->argv[i] = NULL;
	init_cmd(data);
}

t_data	init_struct(char **av, char **env)
{
	t_data	data;

	data.av = av;
	data.env = env;
	data.argv = NULL;
	data.cmd = NULL;
	data.fd = NULL;
	data.pipefd = NULL;
	data.pid = NULL;
	init_malloc(&data);
	open_file(&data);
	init_argv(&data);
	init_pipe(&data);
	return (data);
}
