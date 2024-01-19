/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/19 19:48:47 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_first(t_data *data)
{
	int error;

	error = dup2(data->fd[0], 0);
	if (error == -1)
		clean_exit(data, 'd');
	error = dup2(data->pipefd[1], 1);
	if (error == -1)
		clean_exit(data, 'd');

}

static void	set_last(t_data *data)
{
	int	error;

	error = dup2(data->pipefd[0], 0);
	if (error == -1)
		clean_exit(data, 'd');
	error = dup2(data->fd[1], 1);
	if (error == -1)
		clean_exit(data, 'd');

}

static void	exec_cmd(t_data *data)
{
	int	error;

	close(data->pipefd[data->cmd_n]);
	if (data->cmd_n == 0)
		set_first(data);
	else
		set_last(data);
	close_file(data);
	free_struct(data);
	error = execve(data->cmd, data->argv, data->env);
	if (error == -1)
		clean_exit(data, 'e');
}

static void	finish_cmd(t_data *data)
{
	int		status;

	close_file(data);
	data->cmd_n--;
	while (data->cmd_n >= 0)
	{
		waitpid(data->pid[data->cmd_n], &status, 0);
		ft_printf("status : %d\n", status);
		data->cmd_n--;
	}
	free_struct(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
		return (1);
	data = init_struct(av, env);
	data.cmd_n = 0;
	while (data.cmd_n < 2)
	{
		init_argv(&data);
		data.pid[data.cmd_n] = fork();
		if (data.pid[data.cmd_n] == -1)
			clean_exit(&data, 'f');
		if (data.pid[data.cmd_n] == 0)
			exec_cmd(&data);
		ft_freetab(data.argv);
		if (data.cmd)
			free(data.cmd);
		data.cmd_n++;
	}
	finish_cmd(&data);
	return (0);
}
