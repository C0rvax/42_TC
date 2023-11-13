#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char buff[BUFF_SIZE];

	read(fd, buff, BUFF_SIZE);
	while (ft_strchr(buff, '\n') == 0)

	ft_strlcpy(*line, buff, BUFF_SIZE);
	printf("valeur lu : %s", *line);
	return (1);
	
}
