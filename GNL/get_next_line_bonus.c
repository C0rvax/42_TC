/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:15:13 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/20 13:54:09 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	isend(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_to_result(char *result, const int fd)
{
	char	*buff;
	char	*copy;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(result), free(buff), NULL);
		else if (i == 0)
			break ;
		buff[i] = '\0';
		if (!result)
			result = ft_strnew();
		copy = result;
		result = ft_strjoin(copy, buff);
		free(copy);
		if (isend(result))
			break ;
	}
	return (free(buff), result);
}

char	*stash_memory(char *result)
{
	char	*memory;
	size_t	i;
	size_t	size;

	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	if (result[i] == '\0' || result[i + 1] == '\0')
		return (NULL);
	size = ft_strlen(result) - i;
	memory = ft_substr(result, i + 1, size);
	if (!memory)
		return (free(memory), NULL);
	result[i + 1] = '\0';
	return (memory);
}

char	*get_next_line(const int fd)
{
	static char	*memory[FD_MAX];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(memory[fd]);
		memory[fd] = NULL;
		return (NULL);
	}
	if (memory[fd] && isend(memory[fd]))
		result = memory[fd];
	else
		result = read_to_result(memory[fd], fd);
	if (!result)
		return (NULL);
	memory[fd] = stash_memory(result);
	return (result);
}
