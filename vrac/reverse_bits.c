#include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;
	unsigned char	e;
	unsigned char	f;
	unsigned char	g;
	unsigned char	h;
	unsigned char	res;

	res = 0;
	a = octet << 7;
	b = octet >> 1;
	b = b << 7;
	b = b >> 1;
	c = octet >> 2;
	c = c << 7;
	c = c >> 2;
	d = octet >> 3;
	d = d << 7;
	d = d >> 3;
	e = octet >> 4;
	e = e << 7;
	e = e >> 4;
	f = octet >> 5;
	f = f << 7;
	f = f >> 5;
	g = octet >> 6;
	g = g << 7;
	g = g >> 6;
	h = octet >> 7;
	res |= a;
	res |= b;
	res |= c;
	res |= d;
	res |= e;
	res |= f;
	res |= g;
	res |= h;
	return (res);
}

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

int	main()
{
	unsigned char	res;

	res = reverse_bits(0b01010101);
	write(1, "01010101\n", 9);
	print_bit(res);
	write(1, "\n\n", 2);
	res = reverse_bits(0b10101010);
	write(1, "10101010\n", 9);
	print_bit(res);
	write(1, "\n\n", 2);
	res = reverse_bits(0b00010010);
	write(1, "00010010\n", 9);
	print_bit(res);
	write(1, "\n", 1);
	return (0);
}
