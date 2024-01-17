/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/16 17:49:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct data_s
{
	char	**av;
	char	**env;
	char	**paths;
	char	***argv;
	char	**cmd;
	int		cmd_n;
	int		*fd;
	int		*pipefd;
	int		*pid;
}				t_data;

t_data	init_struct(char **av, char **env);
void	get_paths(t_data *data);
char	*get_cmd(char *cmd, t_data *data);
void	open_file(t_data *data);
void	close_file(t_data *data);
void	clean_exit(t_data *data);

#endif
