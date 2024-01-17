/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/17 01:34:28 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_cmd(t_data *data)
{
	int	error;

	close(data->pipefd[0]);
	data->test = 3;
	error = dup2(data->fd[0], 0);
	if (error == -1)
		clean_exit(data);
	error = dup2(data->pipefd[1], 1);
	if (error == -1)
		clean_exit(data);
	close_file(data);
	error = execve(data->cmd1, data->argv1, data->env);
	if (error == -1)
		clean_exit(data);
}

static void	sec_cmd(t_data *data)
{
	int	error;

	close(data->pipefd[1]);
	error = dup2(data->pipefd[0], 0);
	if (error == -1)
		clean_exit(data);
	error = dup2(data->fd[1], 1);
	if (error == -1)
		clean_exit(data);
	close_file(data);
	error = execve(data->cmd2, data->argv2, data->env);
	if (error == -1)
		clean_exit(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		status;

	if (ac != 5)
		return (1);
	data = init_struct(av, env);
	data.pid = fork();
	if (data.pid == -1)
		clean_exit(&data);
	else if (data.pid == 0)
		first_cmd(&data);
	else
	{
		waitpid(0, &status, 0);
		ft_printf("status : %d\n", status);
		sec_cmd(&data);
	}
	return (0);
}
