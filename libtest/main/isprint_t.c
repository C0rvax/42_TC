#include "libft.h"
#include "libtest.h"

int main()
{
	name("ISPRINT");
	if (ft_isprint(31) == 0)
		display(1, 1);
	else
		display(1, 0);
	if (ft_isprint(32) == 1)
		display(2, 1);
	else
		display(2, 0);
	if (ft_isprint(127) == 0)
		display(3, 1);
	else
		display(3, 0);
	if (ft_isprint(126) == 1)
		display(4, 1);
	else
		display(4, 0);
	return (0);
}
