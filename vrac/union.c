#include <unistd.h>

int	checkbyi(char *str, char c, int index)
{
	if (index == 0)
		return (0);
	while(index--)
	{
		if (c == str[index])
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!checkbyi(av[1], av[1][i], i))
				write(1, &av[1][i], 1);
			i++;
		}
		j = 0;
		while (av[2][j])
		{
			if (!checkbyi(av[1], av[2][j], i) && !checkbyi(av[2], av[2][j], j))
				write(1, &av[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
