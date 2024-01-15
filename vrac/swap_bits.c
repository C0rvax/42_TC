#include <unistd.h>


void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i--)
	{
		bit = octet >> i;
		bit &= 1;
		bit += '0';
		write(1, &bit, 1);
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	end;
	unsigned char	start;
	unsigned char	res;

	end = octet << 4;
	print_bits(end);
	write(1, "\n", 1);
	start = octet >> 4;
	print_bits(start);
	write(1, "\n", 1);
	res = end | start;
	return (res);
}


int	main()
{
	unsigned char	oc = 0b01000001;
	unsigned char	res;

	print_bits(oc);
	write(1, "\n", 1);
	res = swap_bits(oc);
	print_bits(res);
	write(1, "\n", 1);
}
