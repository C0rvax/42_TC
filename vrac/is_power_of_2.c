#include <stdio.h>

int	is_power(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n != 1)
	{
		if	(n % 2 != 0)
			return (0);
		n /= 2;
	}
	return (1);
}

int	main()
{
	printf("4 : %i\n", is_power(4));
	printf("0 : %i\n", is_power(0));
	printf("10 : %i\n", is_power(10));
	printf("14 : %i\n", is_power(14));
	printf("8192 : %i\n", is_power(8192));
}
