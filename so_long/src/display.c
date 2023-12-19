#include "so_long.h"

void	display_sprite(t_data *game, void *sprite, int x, int y)
{
	int	width;
	int	height;

	width = game->sprite.width * x;
	height = game->sprite.height * y;
	ft_printf("x = %d y = %d\n", game->player_x, game->player_y);
	mlx_put_image_to_window(game->init, game->window, sprite, width, height);
}

void	display_back(t_data *game)
{
	int	x;
	int	y;

	y = 1;
	while (game->map[y + 1])
	{
		x = 1;
		while (game->map[y + 1][x + 1])
		{
			if (game->map[y][x] == game->sign.floor)
				display_sprite(game, game->sprite.floor, x, y);
			x++;
		}
		y++;
	}
	display_frame(game, x, y);

}

void	display_frame_top(t_data *game, int x)
{
	display_sprite(game, frameul, 0, 0);
	display_sprite(game, frameur, x, 0);
	while (x-- > 1)
		display_sprite(game, frameu, x, 0);
}

void	display_frame_mid(t_data *game, int x, int y)
{

}
void	display_frame(t_data *game, int x, int y)
{

}
void	display_wall(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == game->sign.wall)
				display_sprite(game, game->sprite.wall, x, y);
			x++;
		}
		y++;
	}

}

int	display(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == game->sign.chicken)
				display_sprite(game, game->sprite.chicken, x, y);
			if (game->map[y][x] == game->sign.player)
				display_sprite(game, game->sprite.player, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

