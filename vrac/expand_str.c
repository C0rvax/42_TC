#include <unistd.h>

int	ispa(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	isok(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ispa(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2 && isok(av[1]))
	{	
		int	i;

		i = 0;
		if (ispa(av[1][0]))
		{
			while (ispa(av[1][i]))
				i++;
		}
		while (av[1][i])
		{
			if (ispa(av[1][i]))
			{
				write(1, "   ", 3);
				while (ispa(av[1][i]))
					i++;
			}
			else
			{
				write(1, &av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
