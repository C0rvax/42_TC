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
		&(game->sprite.width), &(game->sprite.height));
	game->sprite.wall = mlx_xpm_file_to_image(game->init, "./textures/wall.xpm",
		&game->sprite.width, &game->sprite.height);
	game->sprite.chicken = mlx_xpm_file_to_image(game->init, 
		"./textures/chicken.xpm", &game->sprite.width, &game->sprite.height);
	game->sprite.player = mlx_xpm_file_to_image(game->init,
		"./textures/player.xpm", &game->sprite.width, &game->sprite.height);
	game->sprite.exit = mlx_xpm_file_to_image(game->init, "./textures/exit.xpm",
		&game->sprite.width, &game->sprite.height);
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
