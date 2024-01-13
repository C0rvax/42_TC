#include "libft.h"
#include "libtest.h"

int main()
{
	name("MEMCMP");
	unsigned char	s1[18] = "Salut\vc'est\fcool\n!";
	unsigned char	s2[24] = "Salut\vc'est\fmoins cool\n!";
	unsigned char	s3[0] = "";

	if (ft_memcmp(s1, s2, 0) == 0)
		display(1, 1);
	else
		display(1, 0);
	if (ft_memcmp(s1, s2, 12) == 0)
		display(2, 1);
	else
		display(2, 0);
	if (ft_memcmp(s1, s2, 15) < 0)
		display(3, 1);
	else
		display(3, 0);
	return (0);
	
}
