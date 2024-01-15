/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:31:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/15 14:53:09 by aduvilla         ###   ########.fr       */
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
	data->argv1 = ft_split(data->av[2], ' ');
	if (!data->argv1)
		clean_exit(data);
	data->argv2 = ft_split(data->av[3], ' ');
	if (!data->argv2)
		clean_exit(data);
	data->cmd1 = get_cmd(data->argv1[0], data);
	if (!data->cmd1)
		clean_exit(data);
	data->cmd2 = get_cmd(data->argv2[0], data);
	if (!data->cmd2)
		clean_exit(data);
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
