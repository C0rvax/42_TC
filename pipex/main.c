/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/13 01:49:31 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_cmd(t_data *data)
{
	int	d;

	d = dup2(data->fd[0], 0);
	if (d == -1)
		clean_exit(data);
	d = dup2(data->pipefd[1], 1);
	if (d == -1)
		clean_exit(data);
	close_file(data);
	d = execve(data->cmd1, data->argv1, data->env);
	if (d == -1)
		clean_exit(data);
}

static void	sec_cmd(t_data *data)
{
	int	d;

	d = dup2(data->pipefd[0], 0);
	if (d == -1)
		clean_exit(data);
	d = dup2(data->fd[1], 1);
	if (d == -1)
		clean_exit(data);
	close_file(data);
	d = execve(data->cmd2, data->argv2, data->env);
	if (d == -1)
		clean_exit(data);
}

int	main(int ac, char **av, char **env)
{
	int		pid;
	t_data	data;
	int		status;

	if (ac != 5)
		return (1);
	data = init_struct(av, env);
	ft_printf("init struct ok\n");
	pid = fork();
	if (pid == -1)
		clean_exit(&data);
	else if (pid == 0)
		first_cmd(&data);
	else
		sec_cmd(&data);
	waitpid(pid, &status, 0);
	return (0);
}
