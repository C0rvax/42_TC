/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/17 01:43:04 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_data *data)
{
	int	error;

	close(data->pipefd[data->cmd_n]);
	if (data->cmd_n == 0)
	{
		error = dup2(data->fd[0], 0);
		if (error == -1)
			clean_exit(data);
		error = dup2(data->pipefd[1], 1);
		if (error == -1)
			clean_exit(data);
	}
	else
	{
		error = dup2(data->pipefd[0], 0);
		if (error == -1)
			clean_exit(data);
		error = dup2(data->fd[1], 1);
		if (error == -1)
			clean_exit(data);
	}
	close_file(data);
	error = execve(data->cmd[data->cmd_n], data->argv[data->cmd_n], data->env);
	if (error == -1)
		clean_exit(data);
}

static void finish_cmd(t_data *data)
{
	int		status;

	close_file(data);
	ft_printf("au finish pid 1 cmd : %d\n", data->pid[0]);
	ft_printf("au finish pid 2 cmd : %d\n", data->pid[1]);
	waitpid(data->pid[data->cmd_n], &status, 0);
	ft_printf("status : %d\n", status);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
		return (1);
	data = init_struct(av, env);
	ft_puttstr(data.paths, 'q');
	data.cmd_n = 0;
	ft_printf("pid avant : %d\n", getpid());
	while (data.cmd_n < 2)
	{
		data.pid[data.cmd_n] = fork();
		if (data.pid[data.cmd_n] == -1)
			clean_exit(&data);
		if (data.pid[data.cmd_n] == 0)
			exec_cmd(&data);
		data.cmd_n++;
	}
	finish_cmd(&data);
	return (0);
}
