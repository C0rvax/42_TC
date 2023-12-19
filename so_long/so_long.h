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

typedef struct data_s
{
	void		*init;
	void		*window;
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			turns;
	char		**map;
	t_sprite	sprite;
	t_sign		sign;
}			t_data;

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

void	init_sign(t_data *game);
void	init_sprite(t_data *game);
char	**init_map(char *ber, t_data *game);
void	display_sprite(t_data *game, void *sprite, int x, int y);
void	display_back(t_data *game);
void	display_wall(t_data *game);
int		display(t_data *game);
void	main_loop(t_data *game);
int		input_key(int keysym, t_data *game);
void	move_top(t_data *game);
void	move_down(t_data *game);
void	move_left(t_data *game);
void	move_right(t_data *game);
int		end_game(t_data *game);

#endif
