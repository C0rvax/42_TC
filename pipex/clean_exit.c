/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:53:39 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/20 15:06:23 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_data *data)
{
	if (data->paths)
		ft_freetab(data->paths);
	if (data->fd)
		free(data->fd);
	if (data->pipefd)
		free(data->pipefd);
	if (data->pid)
		free(data->pid);
}

void	print_error(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd("\n", 2);
}

void	clean_exit(t_data *data, char c)
{
	if (c == 'm')
		print_error("pipex", strerror(errno));
	if (c == 'p')
		print_error("pipe", "Failure");
	if (c == 'c')
		print_error("command not found", data->av[data->cmd_n + 2]);
	if (c == 'd')
		print_error("dup2", "Failure");
	if (c == 'e')
		print_error(data->av[data->cmd_n + 2], strerror(errno));
	if (c == 'f')
		print_error("fork", strerror(errno));
	if (c == 'i')
		print_error(strerror(errno), data->av[1]);
	if (c == 'o')
		print_error(strerror(errno), data->av[4]);
	close_file(data);
	ft_printf("va tu la \n");
	free_struct(data);
	exit(EXIT_FAILURE);
}
