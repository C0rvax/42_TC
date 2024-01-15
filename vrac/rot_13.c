#include <unistd.h>

int	ft_islower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}	

int	ft_isupper(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	char res;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		if (ft_islower(av[1][i]))
		{
			if (av[1][i] <= 109)
				res = av[1][i] + 13;
			else
				res = av[1][i] - 13;
			write(1, &res, 1);
		}
		else if (ft_isupper(av[1][i]))
		{
			if (av[1][i] <= 77)
				res = av[1][i] + 13;
			else
				res = av[1][i] - 13;
			write(1, &res, 1);
		}
		else
			write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

