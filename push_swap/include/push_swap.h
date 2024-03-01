/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:37:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/01 14:29:15 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
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
void	sort_list(t_data *a, t_data *b);
int		find_in_a(t_data *a, int bcontent);
int		find_in_b(t_data *b, int acontent);
int		find_content(t_data *data, int value);
void	rotate_list(t_lst **first, t_lst **sec, int i, int mode);
void	all_in(t_data *a, t_data *b);
int		exec_swap(int print, t_data *data);
int		exec_push(int print, t_data *in, t_data *out);
int		get_q2(t_data *data, int med, int max);
int		get_q1(t_data *data, int min, int med);
void	push_in_b(t_data *a, t_data *b);
int		get_med(t_data *data, int min, int max);
t_lst	*ft_listnew(int content);
void	ft_listclear(t_data *data);
void	ft_listadd_front(t_data *data, t_lst *new);
void	set_list_max(t_data *data);
void	set_2p(t_lst **p1, t_lst *p2, t_lst **pt1, t_lst *pt2);
#endif
