/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:27:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/19 12:11:20 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct sprite_s
{
	void	*floor;
	void	*wall;
	void	*chicken;
	void	*player;
	void	*exit;
	void	*ennemy;
}			t_sprite;

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
	char		**map;
	int			height;
	int			width;
	int			w_img;
	int			h_img;
	int			player_x;
	int			player_y;
	int			turns;
	int			chicks;
	t_sprite	sprite;
	t_frame		frame;
}			t_data;

int		init_game(char *map, t_data *game);
char	**init_map(char *ber, t_data *game);
int		check_wall(t_data *game);
int		check_ext(char *file, char *ext);
int		is_a_directory(char *ber);
int		check_map_char(char *line);
int		is_no_empty_line(char *line);
int		display(t_data *game);
int		input_key(int keysym, t_data *game);
void	check_exit(t_data *game);
void	game_over(t_data *game);
int		end_game(t_data *game);
char	**tab_dup(char **tab);
void	ft_error(char c);
char	*get_all_lines(char *ber);

#endif
