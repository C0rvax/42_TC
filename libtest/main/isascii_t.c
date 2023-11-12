#include "libft.h"
#include "libtest.h"

int main()
{
	name("ISASCII");
	if (ft_isascii(-1) == 0)
		display(1, 1);
	else
		display(1, 0);
	if (ft_isascii(1) == 1)
		display(2, 1);
	else
	display(2, 0);
	if (ft_isascii(128) == 0)
		display(3, 1);
	else
		display(3, 0);
	if (ft_isascii(127) == 1)
		display(4, 1);
	else
		display(4, 0);
	return (0);
}
