#include <unistd.h>

int	isup(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	islo(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;

		i = 0;
		while (av[1][i])
		{
			if (isup(av[1][i]))
				av[1][i] -= 32;
			else if (islo(av[1][i]))
				av[1][i] += 32;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
