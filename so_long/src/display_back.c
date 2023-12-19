#include "so_long.h"

void	display_frame_top(t_data *game, t_frame *frame, int x)
{
	display_sprite(game, frame->ul, 0, 0);
	display_sprite(game, frame->ur, x, 0);
	while (x-- > 1)
		display_sprite(game, frame->u, x, 0);
}

void	display_frame_mid(t_data *game, t_frame *frame, int x, int y)
{
	int	i;

	i = 0;
	while(++i < y)
	{
		display_sprite(game, frame->l, 0, i);
		display_sprite(game, frame->r, x, i);
	}
}

void	display_frame_bot(t_data *game, t_frame *frame, int x, int y)
{
	display_sprite(game, frame->dl, 0, y);
	display_sprite(game, frame->dr, x, y);
	while (x-- > 1)
		display_sprite(game, frame->d, x, y);
}

void	display_frame(t_data *game, t_frame *frame, int x, int y)
{
	display_frame_top(game, frame, x);
	display_frame_bot(game, frame, x, y);
	display_frame_mid(game, frame, x, y);
}

void	display_back(t_data *game, t_frame *frame)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[++y + 1])
	{
		x = 0;
		while (game->map[y + 1][++x + 1])
		{
			if (game->map[y][x] == game->sign.floor)
				display_sprite(game, game->sprite.floor, x, y);
			if (game->map[y][x] == game->sign.chicken)
				display_sprite(game, game->sprite.chicken, x, y);
			if (game->map[y][x] == game->sign.player)
				display_sprite(game, game->sprite.player, x, y);
			if (game->map[y][x] == game->sign.exit)
				display_sprite(game, game->sprite.exit, x, y);
			if (game->map[y][x] == game->sign.wall)
				display_sprite(game, game->sprite.wall, x, y);
		}
	}
	if (x > 2 && y > 2)
		display_frame(game, frame, x, y);
}

// reduire en faisant ++y et ++x dans les conditions
