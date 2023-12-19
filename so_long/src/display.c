#include "so_long.h"

void	display_sprite(t_data *game, void *sprite, int x, int y)
{
	int	width;
	int	height;

	width = game->sprite.width * x;
	height = game->sprite.height * y;
	mlx_put_image_to_window(game->init, game->window, sprite, width, height);
}

int	display(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[++y + 1])
	{
		x = 0;
		while (game->map[y + 1][++x + 1])
		{
			if (game->map[y][x] == game->sign.chicken)
				display_sprite(game, game->sprite.chicken, x, y);
			if (game->map[y][x] == game->sign.player)
				display_sprite(game, game->sprite.player, x, y);
			if (game->map[y][x] == game->sign.floor)
				display_sprite(game, game->sprite.floor, x, y);
		}
	}
	return (1);
}
