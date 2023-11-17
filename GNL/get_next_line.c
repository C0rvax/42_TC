/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:15:13 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/17 13:43:00 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ischar(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*read_to_result(char *result, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*copy;
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFF_SIZE);
		if (i < 0)
			return (free(result), NULL);
		else if (i == 0)
			break ;
		buff[i] = '\0';
		if (!result)
			result = ft_strnew();
		copy = result;
		result = ft_strjoin(copy, buff);
		free(copy);
		if (ischar(result, '\n'))
			break ;
	}
	return (result);
}

char	*stash_memory(char *result)
{
	char	*memory;
	size_t	i;
	size_t	len;

	if (ischar(result, '\n'))
	{
		i = ischar(result, '\n');
		//if (result[i + 1] == '\0')
		//{
		//	result[i] = '\0';
		//}
	}
	else
		i = ischar(result, '\0');
	if (result[i + 1] == '\0')
	{
		//result[i] = '\0';
		return (NULL);
	}
	len = ft_strlen(result);
	memory = ft_substr(result, i + 1, len - i);
	if (*memory == '\0')
	{
		free(memory);
		return (NULL);
	}
	result[i + 1] = '\0';
	return (memory);
}

char	*get_next_line(const int fd)
{
	static char	*memory;
	char		*result;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(memory);
		return (NULL);
	}
	if (memory && ischar(memory, '\n'))
		result = memory;
	else
		result = read_to_result(memory, fd);
	if (!result)
		return (NULL);
	memory = stash_memory(result);
	return (result);
}
