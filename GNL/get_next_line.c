#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE];
	char	*tmp;

	read(fd, buff, BUFF_SIZE);
	tmp =malloc(sizeof(char) * BUFF_SIZE);
	tmp = ft_strchr(buff, '\n') + 2;
	printf("reste du buffer : %s\n", tmp);
	//printf("taille du buff moins avant ligne : %zu\n", ft_strlen(tmp));
	ft_strlcat(*line, buff, BUFF_SIZE);
	//ft_strlcat(*line, buff, (BUFF_SIZE - ft_strlen(ft_strchr(buff, '\n'))));
	//printf("valeur lu : %s\n", *line);
	return (1);
	
}
