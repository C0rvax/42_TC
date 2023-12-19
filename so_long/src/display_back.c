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

	i = 1;
	while(i < y)
	{
		display_sprite(game, frame->l, 0, y);
		display_sprite(game, frame->r, x, y);	
		i++;
	}
}

void	display_frame_bot(t_data *game, t_frame *frame, int y)
{
	display_sprite(game, frame->dl, 0, 0);
	display_sprite(game, frame->dr, 0, y);
	while (y-- > 1)
		display_sprite(game, frame->d, 0, y);
}

void	display_frame(t_data *game, t_frame *frame, int x, int y)
{
	display_frame_top(game, frame, x);
	display_frame_bot(game, frame, y);
	display_frame_mid(game, frame, x, y);
}

void	display_back(t_data *game, t_frame *frame)
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
	display_frame(game, frame, x, y);
}
