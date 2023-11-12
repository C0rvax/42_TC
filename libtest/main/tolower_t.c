#include "libft.h"
#include "libtest.h"

int main()
{
	name("TOLOWER");
	if (ft_tolower('A') == 'a')
		display(1, 1);
	else
		display(1, 0);
	if (ft_tolower('a') == 'a')
		display(2, 1);
	else
		display(2, 0);
	if (ft_tolower(91) == 91)
		display(3, 1);
	else
		display(3, 0);
	if (ft_tolower(50) == 50)
		display(4, 1);
	else
		display(4, 0);
	return (0);
}
