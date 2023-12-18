#include "so_long.h"

int	input_key(int keysym, t_data *game)
{
	if (keysym == XK_Escape)
		end_game(game);
	if (keysym == XK_w)
		move_top(game);
	if (keysym == XK_d)
		move_down(game);
	if (keysym == XK_a)
		move_left(game);
	if (keysym == XK_s)
		move_right(game);
	return (0);
}

void	move_top(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y -1][x] != game->sign.wall)
	{
		game->map[y - 1][x] = game->sign.player;
		game->map[y][x] = game->sign.floor;
		game->turns++;
		ft_printf("Turns : %d\n", game->turns);
		game->player_y--;
	}
	// check win
}

void	move_down(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y +1][x] != game->sign.wall)
	{
		game->map[y + 1][x] = game->sign.player;
		game->map[y][x] = game->sign.floor;
		game->turns++;
		ft_printf("Turns : %d\n", game->turns);
		game->player_y++;
	}
	// check win
}

void	move_left(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != game->sign.wall)
	{
		game->map[y][x - 1] = game->sign.player;
		game->map[y][x] = game->sign.floor;
		game->turns++;
		ft_printf("Turns : %d\n", game->turns);
		game->player_x--;
	}
	// check win
}

void	move_right(t_data *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != game->sign.wall)
	{
		game->map[y][x + 1] = game->sign.player;
		game->map[y][x] = game->sign.floor;
		game->turns++;
		ft_printf("Turns : %d\n", game->turns);
		game->player_x++;
	}
	// check win
}
