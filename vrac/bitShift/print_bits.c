#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i--)
	{
		printf("i : %i\n", i);
		bit = octet >> i;
		bit &= 1;
		bit += '0';
		write(1, &bit, 1);
	}
}

int	main()
{
	print_bits(42);
	write(1, "\n", 1);
	print_bits(128);
	write(1, "\n", 1);
}
