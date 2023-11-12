#include "libft.h"
#include "libtest.h"

int main()
{
	name("MEMMOVE");
	unsigned char	s1[18] = "Salut\vc'est\fcool\n!";
	unsigned char	s2[18] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	ft_memmove(s2, s1, 5);
	if (s2[3] == 'u')
		display(1, 1);
	else
		display(1, 0);
	if (s2[5] == '\0')
		display(2, 1);
	else
		display(2, 0);
	ft_memmove(s1 + 3, s1, 14);
	if (s1[11] == 'e')
		display(3, 1);
	else
		display(3, 0);
	return (0);
	
}
