#include "get_next_line.h"

static int	isend(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
	i++;
	}
	return (0);
}
/*
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
static char	*split_buff(char *s)
{

}
*/

static void	read_to_tmp(char *tmp, const int fd)
{
	char	buff[BUFF_SIZE];
	static int	i;

	i = i + read(fd, buff, BUFF_SIZE);
	printf("buff : %s\n", buff);
	printf("lu : %d\n", i);
	printf("tmp : %s\n", tmp);
	ft_strlcat(tmp, buff, i + 1);
}

char	*get_next_line(const int fd)
{
	static char	tmp[255];
//	char		*result;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0)
		return (NULL);
	while (!isend(tmp))
	{
		read_to_tmp(tmp, fd);
		printf("tmp : %s\n", tmp);
	}
//	result = split_buff(tmp);
//	printf("result : %s\n", result);
//	return (result);
	/*i = count_index(buff, BUFF_SIZE);
	index = index + i;
	ft_strlcat(*line, buff, index + 1);
	tmp = ft_substr(buff, i, BUFF_SIZE - i);
	printf("Taille a copier : %zu\n", i); 
	printf("GNL : %s\n", *line);
	printf("reste du buffer : %s\n", tmp);
	read(fd, buff, BUFF_SIZE);
	*/
	return (tmp);

}
