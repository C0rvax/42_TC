#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct sprite_s
{
	int		height;
	int		width;
	void	*floor;
	void	*wall;
	void	*chicken;
	void	*player;
	void	*exit;
}			t_sprite;

typedef struct sign_s
{
	char	floor;
	char	wall;
	char	chicken;
	char	player;
	char	exit;
}			t_sign;

typedef struct frame_s
{
	void	*ul;
	void	*u;
	void	*ur;
	void	*l;
	void	*r;
	void	*dl;
	void	*d;
	void	*dr;
}			t_frame;

typedef struct data_s
{
	void		*init;
	void		*window;
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			turns;
	int			chicks;
	char		**map;
	t_sprite	sprite;
	t_sign		sign;
	t_frame		frame;
}			t_data;

void	initialize_game(t_data *game);
void	init_sign(t_data *game);
void	init_sprite(t_data *game);
char	**init_map(char *ber, t_data *game);
int		check_map(t_data *game);
int		check_tiles(t_data *game, int p, int e);
int		check_tile_number(t_data *game, int p, int e);
int		check_wall(t_data *game);
void		flood_test(char **map, int x, int y);
void	display_sprite(t_data *game, void *sprite, int x, int y);
void	display_back(t_data *game);
void	display_frame(t_data *game, int x, int y);
void	display_frame_top(t_data *game, int x);
void	display_frame_bot(t_data *game, int x, int y);
void	display_frame_mid(t_data *game, int x, int y);
int		display(t_data *game);
void	main_loop(t_data *game, char *title);
int		input_key(int keysym, t_data *game);
void	move_top(t_data *game);
void	move_down(t_data *game);
void	move_left(t_data *game);
void	move_right(t_data *game);
void	add_chicks(t_data *game);
void	check_exit(t_data *game);
void	free_image(t_data *game);
int		end_game(t_data *game);

#endif
