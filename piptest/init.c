/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:31:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/18 13:05:59 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipe(t_data *data)
{
	int	p;

	data->pipefd = malloc(sizeof(int) * 2);
	if (!data->pipefd)
		clean_exit(data);
	p = pipe(data->pipefd);
	if (p == -1)
		clean_exit(data);
}

static void	init_argv(t_data *data)
{
	data->argv = malloc(sizeof(char **) * 3);
	if (!data->argv)
		clean_exit(data);
	data->argv[0] = ft_split(data->av[2], ' ');
	if (!data->argv[0])
		clean_exit(data);
	data->argv[1] = ft_split(data->av[3], ' ');
	if (!data->argv[1])
		clean_exit(data);
	data->argv[2] = NULL;
	data->cmd = malloc(sizeof(char *) * 3);
	if (!data->cmd)
		clean_exit(data);
	data->cmd[0] = get_cmd(data->argv[0][0], data);
	if (!data->cmd[0])
		clean_exit(data);
	data->cmd[1] = get_cmd(data->argv[1][0], data);
	if (!data->cmd[1])
		clean_exit(data);
	data->cmd[2] = NULL;
}

t_data	init_struct(char **av, char **env)
{
	t_data	data;

	data.av = av;
	data.env = env;
	get_paths(&data);
	if (!data.paths)
		clean_exit(&data);
	init_argv(&data);
	open_file(&data);
	init_pipe(&data);
	return (data);
}
