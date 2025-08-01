/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:31 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/05 16:51:38 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wait_and_clean(t_data *data)
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
		if (i == data->cmd_max - 1 && WIFEXITED(status))
		{
			status_code = WEXITSTATUS(status);
		}
		i++;
	}
	free_struct(data);
	return (status_code);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		status_code;

	if (ac < 5)
		return (print_error("Invalid number of argument",
				"./pipex infile cmd1 cmd2 outfile"), 1);
	if (ac < 6 && !ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
		return (print_error("Invalid number of argument",
				"./pipex here_doc LIMITER cmd1 cmd2 outfile"), 1);
	if (!env || env[0] == NULL || env[0][0] == '\0')
		return (ft_putstr_fd("Environment: no variable set!\n", 2), 1);
	data = init_struct(ac, av, env);
	data.cmd_n = 0;
	while (data.cmd_n < data.cmd_max)
	{
		data.pid[data.cmd_n] = fork();
		if (data.pid[data.cmd_n] == -1)
			clean_exit(&data, FORK, 1);
		if (data.pid[data.cmd_n] == 0)
			exec_cmd(&data);
		data.cmd_n++;
	}
	status_code = wait_and_clean(&data);
	return (status_code);
}
