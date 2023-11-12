#include "libft.h"
#include "libtest.h"

int main()
{
	name("ISALHA");
	if (ft_isalpha(0) == 0)
		display(1, 1);
	else
		display(1, 0);
	if (ft_isalpha('a') == 1)
		display(2, 1);
	else
		display(2, 0);
	if (ft_isalpha(96) == 0)
		display(3, 1);
	else
		display(3, 0);
	if (ft_isalpha('Z') == 1)
		display(4, 1);
	else
		display(4, 0);
	return (0);
}
