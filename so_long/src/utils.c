#include "so_long.h"

char	**tab_dup(char **tab)
{
	int i;
	char	**res;

	i = 0;
	while (tab[i])
		i++;
	res = malloc(sizeof(char *) * i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strdup(tab[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
