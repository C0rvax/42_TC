#include "libft.h"
#include "libtest.h"

int	main()
{
	name("SPLIT");
	char	**tab;
	char	*s;
	unsigned int	i;

	i = 0;
	s = "Salut c'est cool !";
	tab = ft_split(s, 'c');
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
