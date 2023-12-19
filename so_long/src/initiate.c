#include "so_long.h"
#include <mlx.h>

void	init_sign(t_data *game)
{
	game->sign.floor = '0';
	game->sign.wall = 'W';
	game->sign.chicken = 'C';
	game->sign.player = 'P';
	game->sign.exit = 'E';
}

void	init_sprite(t_data *game)
{
	game->sprite.height = 32;
	game->sprite.width = 32;
	game->sprite.floor = mlx_xpm_file_to_image(game->init, "./textures/floor.xpm",
		&game->sprite.width, &game->sprite.height);
	game->sprite.wall = mlx_xpm_file_to_image(game->init, "./textures/wall.xpm",
		&game->sprite.width, &game->sprite.height);
	game->sprite.chicken = mlx_xpm_file_to_image(game->init, 
		"./textures/chicken.xpm", &game->sprite.width, &game->sprite.height);
	game->sprite.player = mlx_xpm_file_to_image(game->init,
		"./textures/player.xpm", &game->sprite.width, &game->sprite.height);
	game->sprite.exit = mlx_xpm_file_to_image(game->init, "./textures/exit.xpm",
		&game->sprite.width, &game->sprite.height);
	game->player_x = 2;
	game->player_y = 2;
}

void	init_frame(t_data *game, t_frame *frame)
{
	frame->ul = mlx_xpm_file_to_image(game->init, "./textures/frameul.xpm",
		&game->sprite.width, &game->sprite.height);
	frame->u = mlx_xpm_file_to_image(game->init, "./textures/frameu.xpm",
		&game->sprite.width, &game->sprite.height);
	frame->ur = mlx_xpm_file_to_image(game->init, "./textures/frameur.xpm",
		&game->sprite.width, &game->sprite.height);
	frame->l = mlx_xpm_file_to_image(game->init, "./textures/framel.xpm",
		&game->sprite.width, &game->sprite.height);
	frame->r = mlx_xpm_file_to_image(game->init, "./textures/framer.xpm",
		&game->sprite.width, &game->sprite.height);
	frame->dl = mlx_xpm_file_to_image(game->init, "./textures/framedl.xpm",
		&game->sprite.width, &game->sprite.height);
	frame->d = mlx_xpm_file_to_image(game->init, "./textures/framed.xpm",
		&game->sprite.width, &game->sprite.height);
	frame->dr = mlx_xpm_file_to_image(game->init, "./textures/framedr.xpm",
		&game->sprite.width, &game->sprite.height);
}

void	initialize_game(t_data *game)
{
	t_frame	frame;

	game->turns = 0;
	game->init = mlx_init();
	init_sign(game);
	init_sprite(game);
	init_frame(game, &frame);

}

char	**init_map(char *ber, t_data *game)
{
	int	fd;
	char	**res;

	res = ft_split("WWWWWWWWWWeWC000000EWeWP00CW0WWWeWWWWWWWWWW", 'e');

	game->width = 10;
	game->height = 4;
	game->map = res;
	return (game->map);

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nCan't open map !\n"), NULL);

}
