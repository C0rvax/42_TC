#include "libft.h"
#include "libtest.h"

int	main()
{
	name("BZERO");
	char	s[18] = "Salut c'est cool !";
	ft_bzero(s, 0);
	if (s[0] == 'S')
		display(1, 1);
	else
		display(1, 0);
	ft_bzero(s, 1);
	if (s[0] == '\0')
		display(2 , 1);
	else
		display(2, 0);
	if (s[1] == 'a')
		display(3, 1);
	else
		display(3, 0);

}
