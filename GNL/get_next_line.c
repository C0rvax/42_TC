#include "get_next_line.h"

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

	read(fd, buff, BUFF_SIZE);
	index = count_index(buff, BUFF_SIZE);
	ft_strlcat(*line, buff, index + 1);
	tmp = ft_substr(buff, index, BUFF_SIZE - index);
	printf("Taille a copier : %d\n", count_index(buff, BUFF_SIZE)); 
	printf("GNL : %s\n", *line);
	printf("reste du buffer : %s\n", tmp);
	free(tmp);
	read(fd, buff, BUFF_SIZE);
	index = count_index(buff, BUFF_SIZE);
	ft_strlcat(*line, buff, index + 1);
	tmp = ft_substr(buff, index, BUFF_SIZE - index);
	printf("Taille a copier : %d\n", count_index(buff, BUFF_SIZE)); 
	printf("GNL : %s\n", *line);
	printf("reste du buffer : %s\n", tmp);
	free(tmp);
	read(fd, buff, BUFF_SIZE);
	index = count_index(buff, BUFF_SIZE);
	ft_strlcat(*line, buff, index + 1);
	tmp = ft_substr(buff, index, BUFF_SIZE - index);
	printf("Taille a copier : %d\n", count_index(buff, BUFF_SIZE)); 
	printf("GNL : %s\n", *line);
	printf("reste du buffer : %s\n", tmp);
	return (1);

}
