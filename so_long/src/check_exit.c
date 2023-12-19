#include "so_long.h"

void	add_chicks(t_data *game)
{
	game->chicks--;
}

void	check_exit(t_data *game)
{
	if (game->chicks == 0)
	{
		game->turns++;
		ft_printf("\nYou Win !!!\nTurns : %d\n", game->turns);
		end_game(game);
	}
}
