#include "so_long.h"

void	display_sprite(t_data *game, void *sprite, int x, int y)
{
	int	width;
	int	height;

	width = game->sprite.width * x;
	height = game->sprite.height * y;
	mlx_put_image_to_window(game->init, game->window, sprite, width, height);
}

void	display_back(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			ft_printf("dans back");
			if (game->map[y][x] == game->sign.floor)
				display_sprite(game, game->sprite.floor, x, y);
			x++;
		}
		y++;
	}

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

