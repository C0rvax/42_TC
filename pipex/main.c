/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/20 20:12:48 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_and_clean(t_data *data)
{
	int	status;
	int	status_code;
	int	i;

	i = 0;
	status_code = 0;
	close_file(data);
	while (i < data->cmd_max)
	{
		waitpid(data->pid[i], &status, 0);
		if (WIFEXITED(status))
			status_code = WEXITSTATUS(status);
		ft_printf("status : %d\n", status_code);
		i++;
	}
	free_struct(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
		return (print_error("Invalid number of argument",
				"./pipex infile cmd1 cmd2 outfile\n"), 1);
	data = init_struct(ac, av, env);
	data.cmd_n = 0;
	while (data.cmd_n < data.cmd_max)
	{
		data.pid[data.cmd_n] = fork();
		if (data.pid[data.cmd_n] == -1)
			clean_exit(&data, 'f');
		if (data.pid[data.cmd_n] == 0)
			exec_cmd(&data);
		data.cmd_n++;
	}
	wait_and_clean(&data);
	return (0);
}
