#include "libft.h"
#include "libtest.h"

int main()
{
	name("ISALNUM");
	if (ft_isalnum(47) == 0)
		display(1, 1);
	else
		display(1, 0);
	if (ft_isalnum(53) == 1)
		display(2, 1);
	else
		display(2, 0);
	if (ft_isalnum(61) == 0)
		display(3, 1);
	else
		display(3, 0);
	if (ft_isalnum(115) == 1)
		display(4, 1);
	else
		display(4, 0);
	return (0);
}
