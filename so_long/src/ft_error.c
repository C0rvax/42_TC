#include "so_long.h"

void	ft_error(char c)
{
	if (c == 'w')
		ft_printf("Error\nInvalid map : not surrounded by walls !");
	if (c == 'f')
		ft_printf("Error\nInvalid map : no path to exit !");
	if (c == 'e')
		ft_printf("Error\nInvalid map : need 1 exit !");
	if (c == 'p')
		ft_printf("Error\nInvalid map : need 1 player !");
	if (c == 'c')
		ft_printf("Error\nInvalid map : need minimum 1 chicken !");
}
