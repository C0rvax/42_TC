#include <unistd.h>

void	print_bit(unsigned char octet)
{
	int i;
	unsigned char res;

	i = 8;
	while (i--)
	{
		res = octet >> i;
		res &= 1;
		res += '0';
		write (1, &res, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	tab[8];
	unsigned char	res;
	int				i;

	i = 0;
	res = 0;
	while (i <= 7)
	{
		tab[i] = octet >> i;
		tab[i] <<= 7;
		tab[i] >>= i;
		i++;
	}
	while (i--)
		res |= tab[i];
	return (res);
}

int	main()
{
	unsigned char	res;
	unsigned char	res1;
	unsigned char	res2;

	res = reverse_bits(85);
	write(1, "01010101\n", 9);
	print_bit(res);
	write(1, "\n\n", 2);
	res1 = reverse_bits(170);
	write(1, "10101010\n", 9);
	print_bit(res1);
	write(1, "\n\n", 2);
	res2 = reverse_bits(18);
	write(1, "00010010\n", 9);
	print_bit(res2);
	write(1, "\n", 1);
	return (0);
}
