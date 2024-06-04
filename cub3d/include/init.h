/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:24:10 by aduvilla          #+#    #+#             */
/*   Updated: 2024/06/05 00:55:53 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <fcntl.h>
# include "get_next_line.h"

# define IS_DIR ": is a directory"
# define EXTENSION ": is not .cub extension"
# define MALLOC ": cannot allocate memory"

/*------------ STRUCT -------------*/
typedef struct s_sprite
{
	void		*east;
	void		*west;
	void		*north;
	void		*south;
}			t_sprite;

typedef struct s_scene

{
	char 		**map;
	int			f_color;
	int			c_color;
	float		start_x;
	float		start_y;
	t_sprite	sprite;
}			t_scene;

int		map_error(char *s1, char *s2, int status);

char	*get_all_lines(char *ber);
#endif
