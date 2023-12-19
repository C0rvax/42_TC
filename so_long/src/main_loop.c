# include "so_long.h"

int	end_game(t_data *game, t_frame *frame)
{
	int		i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		mlx_destroy_image(game->init, game->sprite.wall);
		mlx_destroy_image(game->init, game->sprite.floor);
		mlx_destroy_image(game->init, game->sprite.chicken);
		mlx_destroy_image(game->init, game->sprite.player);
		mlx_destroy_image(game->init, game->sprite.exit);
		mlx_destroy_image(game->init, frame->ul);
		mlx_destroy_image(game->init, frame->ur);
		mlx_destroy_image(game->init, frame->u);
		mlx_destroy_image(game->init, frame->l);
		mlx_destroy_image(game->init, frame->r);
		mlx_destroy_image(game->init, frame->dl);
		mlx_destroy_image(game->init, frame->dr);
		mlx_destroy_image(game->init, frame->d);
		mlx_destroy_window(game->init, game->window);
	}
	mlx_destroy_display(game->init);
	free(game->init);
	exit(0);
}

void	main_loop(t_data *game, t_frame *frame)
{
	int	x;
	int	y;

	x = game->width * game->sprite.width;
	y = game->height * game->sprite.height;
	game->window = mlx_new_window(game->init, x, y, "So_long");
	if (!game->window)
		return (free(game->init));
	display_back(game, frame);
	//display_wall(game);
	mlx_loop_hook(game->init, &display, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, &input_key, game);
	mlx_hook(game->window, 17, 0, &end_game, game);
	mlx_loop(game->init);
	end_game(game, frame);
}
