/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:59:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/12 16:01:03 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(t_data data)
{
	int		i;
	char	*path;
	char	**res;

	i = 0;
	path = NULL;
	while (data.env[i])
	{
		if (ft_strnstr(data.env[i], "PATH=", 5) != NULL)
			path = data.env[i];
		i++;
	}
	res = ft_split(path, ':');
	return (res);
}
