/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/20 15:10:53 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_first(t_data *data)
{
	int	error;

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
	init_argv(data);
//	free_struct(data);
	error = execve(data->cmd, data->argv, data->env);
	if (error == -1)
		clean_exit(data, 'e');
}

static void	wait_and_clean(t_data *data)
{
	int	status;
	int	status_code;

	status_code = 0;
	close_file(data);
	data->cmd_n--;
	while (data->cmd_n >= 0)
	{
		waitpid(data->pid[data->cmd_n], &status, 0);
		if (WIFEXITED(status))
			status_code = WEXITSTATUS(status);
		ft_printf("status : %d\n", status_code);
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
		data.pid[data.cmd_n] = fork();
		if (data.pid[data.cmd_n] == -1)
			clean_exit(&data, 'f');
		if (data.pid[data.cmd_n] == 0)
			exec_cmd(&data);
//		ft_freetab(data.argv);
//		free(data.cmd);
//		data.cmd = NULL;
		data.cmd_n++;
	}
	wait_and_clean(&data);
	return (0);
}
