#include "libft.h"
#include "ft_printf.h"
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	ft_putstr("maybe\n");
//	ft_printf("Youhou ca marche");
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	mlx_loop(mlx);
}

