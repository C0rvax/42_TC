/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:37:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/23 18:21:09 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
	struct s_lst	*prev;
}			t_lst;

typedef struct data_s
{
	t_lst	*list;
	int		size;
	int		max;
	int		min;
}			t_data;

int		u_never_know(t_data *a);
int		*check_list(char **av, int size);
void	exec_instructions(t_data *a, t_data *b);
void	rotate_list(t_lst **first, t_lst **sec, int i, int mode);
int		exec_swap(int print, t_data *data);
int		exec_push(int print, t_data *in, t_data *out);
t_lst	*ft_listnew(int content);
void	ft_listclear(t_data *data);
void	ft_listadd_front(t_data *data, t_lst *new);
void	set_list_max(t_data *data);
void	set_2p(t_lst **p1, t_lst *p2, t_lst **pt1, t_lst *pt2);
#endif
