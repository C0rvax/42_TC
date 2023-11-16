#include "get_next_line.h"

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

char	*read_to_tmp(char *tmp, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*cpy;
	int	i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFF_SIZE);
		if (i < 0)
		{
			free(tmp);
			return (NULL);
		}
		else if (i == 0)
			return (tmp);
		buff[i] = '\0';
		if (!tmp)
			tmp = buff;
		else
		{
			cpy = tmp;
			tmp = ft_strjoin(cpy, buff);
			free(cpy);
			cpy = NULL;
		}
		if (isend(buff))
			return (tmp);
	}
	return (tmp);
}

char	*get_next_line(const int fd)
{
	static char	*tmp;
	char		*result;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	result = read_to_tmp(tmp, fd);
	printf("result : %s\n", result);
	return (result);
}
