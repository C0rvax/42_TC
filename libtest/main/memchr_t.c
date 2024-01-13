#include "libft.h"
#include "libtest.h"

int main()
{
	name("MEMCHR");
	unsigned char	s[18] = "Salut\vc'est\fcool\n!";
	unsigned char	*test;

	test = (char *)ft_memchr(s, 'c', 10);
	if (test[2] == 'e')
		display(1, 1);
	else
		display(1, 0);
	if (!ft_memchr(s, 'c', 5))
		display(2, 1);
	else
		display(2, 0);
	test = (char *)ft_memchr(s, 't', 15);
	if (test[4] == 'e')
		display(3, 1);
	else
		display(3, 0);
	return (0);
	
}
