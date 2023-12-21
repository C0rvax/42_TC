#include "so_long.h"

int	main(int ac, char **ag)
{
	t_data	game;

	if (ac != 2)
	{
		ft_printf("Error\nSo_long need a .ber as argument !\n");
		return (0);
	}
	initialize_game(&game);
	game.map = init_map(ag[1], &game);
	if (!game.map)
		return (0);
	main_loop(&game, ag[0]);
	return (1);
}
