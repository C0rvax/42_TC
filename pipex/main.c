/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/15 17:08:16 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_cmd(t_data *data)
{
	int	in;
	int	out;
	int e;

	close(data->pipefd[0]);
	ft_printf("test child : %d\n", data->test);
	data->test = 3;
	ft_printf("pid child : %d\n", data->pid);
	ft_printf("arrive dans le child\n");
	ft_printf("fd in : %d\n", data->fd[0]);
	in = dup2(data->fd[0], 0);
	ft_printf("fd in : %d\n", data->fd[0]);
	ft_printf("d de dup : %i\n", in);
	if (in == -1)
		clean_exit(data);
	ft_printf("ici\n");
	ft_printf("pifd : %i\n", data->pipefd[1]);
	out = dup2(data->pipefd[1], 1);
	ft_printf("ALLLOOOOO !!!!!\n");
	ft_printf("d de dup : %i\n", out);
	if (out == -1)
		clean_exit(data);
	close_file(data);
	ft_printf("avant exec");
	e = execve(data->cmd1, data->argv1, data->env);
	if (e == -1)
		clean_exit(data);
	ft_printf("child finish");
}

static void	sec_cmd(t_data *data)
{
	int	d;

	close(data->pipefd[1]);
	ft_printf("pifd parent : %i\n", data->pipefd[1]);
	ft_printf("pid parent : %d\n", data->pid);
	ft_printf("test parent : %d\n", data->test);
	ft_printf("si la pas bon\n");
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
	t_data	data;
	int		status;

	if (ac != 5)
		return (1);
	data = init_struct(av, env);
	ft_puttstr(data.argv1);
	ft_puttstr(data.argv2);
	ft_printf("cmd : %s\n", data.cmd1);
	ft_printf("cmd : %s\n", data.cmd2);
	data.test = 5;
	data.pid = fork();
	ft_printf("pid : %d\n", data.pid);
	if (data.pid == -1)
		clean_exit(&data);
	else if (data.pid == 0)
		first_cmd(&data);
	else
	{
		waitpid(0, &status, 0);
		sec_cmd(&data);
	}
	return (0);
}
