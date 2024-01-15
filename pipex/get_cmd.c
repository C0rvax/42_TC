/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:59:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/15 18:00:38 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**add_slash(char **path)
{
	int		i;
	char	*copy;

	i = 0;
	while (path[i])
	{
		copy = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(copy);
		if (!path[i])
			return (ft_freetab(path), NULL);
		i++;
	}
	return (path);
}

void	get_paths(t_data *data)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (data->env[i])
	{
		if (ft_strnstr(data->env[i], "PATH=", 5))
		{
			path = ft_substr(data->env[i], 5, ft_strlen(data->env[i]));
			if (!path)
				return ;
			data->paths = ft_split(path, ':');
			free(path);
			if (!data->paths)
				return ;
			data->paths = add_slash(data->paths);
			return ;
		}
		i++;
	}
}

char	*get_cmd(char *cmd, t_data *data)
{
	int		i;
	int		a;
	char	*path;

	i = 0;
	while (data->paths[i])
	{
		path = ft_strjoin(data->paths[i], cmd);
		if (!path)
			return (NULL);
		a = access(path, F_OK | X_OK);
		if (a == 0)
			return (path);
		free(path);
		path = NULL;
		i++;
	}
	a = access(cmd, F_OK | X_OK);
	if (a == 0)
		return (cmd);
	return (NULL);
}
