/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:59:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/19 20:44:34 by aduvilla         ###   ########.fr       */
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

char	**get_paths(char **env)
{
	int		i;
	char	*line;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			line = ft_substr(env[i], 5, ft_strlen(env[i]));
			if (!line)
				return (NULL);
			path = ft_split(line, ':');
			free(line);
			if (!path)
				return (NULL);
			path = add_slash(path);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*get_cmd(char *cmd, char **paths)
{
	int		i;
	int		a;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
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
