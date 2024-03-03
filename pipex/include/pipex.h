/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/03 13:33:42 by aduvilla         ###   ########.fr       */
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
	char	**paths;
	char	**argv;
	char	*cmd;
	int		hd;
	int		cmd_n;
	int		cmd_max;
	int		*fd;
	int		**pipefd;
	int		*pid;
}				t_data;

t_data	init_struct(int ac, char **av, char **env);
void	get_paths(t_data *data);
void	init_argv(t_data *data);
void	free_struct(t_data *data);
char	*get_cmd(char *cmd, t_data *data);
void	exec_cmd(t_data *data);
void	open_file(t_data *data);
void	close_file(t_data *data);
void	clean_exit(t_data *data, char c);
void	print_error(char *s1, char *s2);

#endif
