#include <stdio.h>

int			main(int ac, char **av)
{
	int		        thirty_two_bits;
    unsigned char   one_byte;

    thirty_two_bits = 3; // 1)
    one_byte = 46;

    printf("binary value : %bd\n", thirty_two_bits);
    thirty_two_bits <<= 1; // 2)
    printf("new binary value : %bd\n", thirty_two_bits);
    thirty_two_bits >>= 1; // 3)
    printf("new binary value : %bd\n", thirty_two_bits);
    thirty_two_bits &= 1; // 4)
    printf("new binary value : %bd\n", thirty_two_bits);

    one_byte = 46; // reminder
    printf("binary value : %bd\n", one_byte);
    one_byte |= 1; // 5)
    printf("new binary value : %bd\n", one_byte);
    one_byte &= ~1; // 6)
    printf("back to original value : %bd\n", one_byte);
    one_byte ^= 0b11010000; // 7) 00101110 = 00101110 ^ 11010000
    printf("new binary value : %bd\n", one_byte);
	return (0);
}
