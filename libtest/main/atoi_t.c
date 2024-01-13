#include "libft.h"
#include "libtest.h"

int	main()
{
	name("ATOI");
	if (ft_atoi("-2147483648") == atoi("-2147483648"))
		display(1, 1);
	else
		display(1, 0);
	if (ft_atoi("0") == 0)
		display(2, 1);
	else
		display(2, 0);
	if (ft_atoi("42") == 42)
		display(3, 1);
	else
		display(3, 0);
	if (ft_atoi("2147483647") == 2147483647)
		display(4, 1);
	else
		display(4, 0);
	return (0);
}
