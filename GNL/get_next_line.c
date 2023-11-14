#include "get_next_line.h"

static int	isend(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	count_index(char *buf, size_t bsize)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while(buf[i] && i < bsize)
	{
		if (buf[i] == '\n')
			return (count);
		i++;
		count++;
	}
	return (count);
}

int	get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	static char	*tmp;
	size_t		index;
	size_t		i;

	index = 0;
	read(fd, buff, BUFF_SIZE);
	printf("buff : %s\n", buff);
	while (!isend(buff, BUFF_SIZE))
	{
		i = BUFF_SIZE;
		index = index + i;
		ft_strlcat(*line, buff, index + 1);
		printf("Taille a copier : %zu\n", i); 
		printf("GNL : %s\n", *line);
		printf("reste du buffer : %s\n", tmp);
		read(fd, buff, BUFF_SIZE);
	}
	i = count_index(buff, BUFF_SIZE);
	index = index + i;
	ft_strlcat(*line, buff, index + 1);
	tmp = ft_substr(buff, i, BUFF_SIZE - i);
	printf("Taille a copier : %zu\n", i); 
	printf("GNL : %s\n", *line);
	printf("reste du buffer : %s\n", tmp);
	read(fd, buff, BUFF_SIZE);
	return (1);

}
