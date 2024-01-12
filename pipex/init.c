#include "pipex.h"

t_data	init_struct(int ac, char **av, char **env)
{
	t_data	data;

	data.ac = ac;
	data.av = av;
	data.env = env;
	data.paths = get_path(data);
	return (data);
}
