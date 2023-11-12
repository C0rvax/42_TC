#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char buff[BUFF_SIZE];

	read(fd, buff, BUFF_SIZE);

	
}
