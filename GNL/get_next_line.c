#include "get_next_line.h"

size_t	isend(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
	i++;
	}
	return (0);
}

char	*read_to_result(char *result, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*copy;
	int	i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFF_SIZE);
		if (i < 0)
		{
			free(result);
			return (NULL);
		}
		else if (i == 0)
			break;
		buff[i] = '\0';
		if (!result)
			result = ft_strnew();
		copy = result;
		result = ft_strjoin(copy, buff);
		free(copy);
		if (isend(buff))
			break;
	}
	return (result);
}

char	*stash_memory(char *result)
{
	char	*mem;
	size_t	i;
	size_t	len;

	i = isend(result);
	len = ft_strlen(result);
	mem = ft_substr(result, i + 1, len - i);
	result[i + 1] = '\0';
	return (mem);
}

char	*get_next_line(const int fd)
{
	static char	*memory;
	char		*result;

	printf("memory start : %s\n", memory);
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	result = read_to_result(memory, fd);
	memory = stash_memory(result);
	printf("memory finish : %s\n", memory);
	return (result);
}
