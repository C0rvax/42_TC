/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/19 20:43:32 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct data_s
{
	char	**av;
	char	**env;
	char	***argv;
	char	**cmd;
	int		*fd;
	int		*pipefd;
	int		*pid;
	int		cmd_n;
}				t_data;

t_data	init_struct(char **av, char **env);
char	**get_paths(char **env);
void	free_struct(t_data *data);
char	*get_cmd(char *cmd, char **paths);
void	open_file(t_data *data);
void	close_file(t_data *data);
void	clean_exit(t_data *data, char c);

#endif
