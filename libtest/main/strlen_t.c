#include "libft.h"
#include "libtest.h"

int	main()
{
	name("STRLEN");
	if(ft_strlen("SA\tlut\rt c'est c00l !") == 21)
		display(1, 1);
	else
		display(1, 0);
	if (ft_strlen("") == 0)
		display(2, 1);
	else
		display(2, 0);
	return (0);
}

