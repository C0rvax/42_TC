/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/15 15:01:42 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_cmd(t_data *data)
{
	int	d;

	ft_printf("arrive dans le child\n");
	clean_exit(data);
	d = dup2(data->fd[0], 0);
	if (d == -1)
		clean_exit(data);
	d = dup2(data->pipefd[1], 1);
	if (d == -1)
		clean_exit(data);
	close_file(data);
	ft_printf("avant exec");
	d = execve(data->cmd1, data->argv1, data->env);
	if (d == -1)
		clean_exit(data);
	ft_printf("child finish");
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
	ft_puttstr(data.argv1);
	ft_puttstr(data.argv2);
	ft_printf("cmd : %s\n", data.cmd1);
	ft_printf("cmd : %s\n", data.cmd2);
	pid = fork();
	ft_printf("pid : %d", pid);
	if (pid == -1)
		clean_exit(&data);
	else if (pid == 0)
	{
		ft_printf("go pid 0\n");
		first_cmd(&data);
	}
	else
	{
		wait(&status);
		ft_printf("parent attend");
//		waitpid(pid, &status, 0);
		sec_cmd(&data);
	}
	return (0);
}
