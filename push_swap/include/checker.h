/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:37:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/01 14:30:46 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

int		u_never_know(t_data *a, t_data *b);
int		*check_list(char **av, int size);
void	rotate_list(t_lst **a, t_lst **b, int index);
int		indexe(char **cmd, char *instruction);
int		instructions(t_data *a, t_data *b);
int		exec_swap(t_data *a, t_data *b, int index);
int		exec_push(int print, t_data *in, t_data *out);
char	*get_all_lines(int fd);
t_lst	*ft_listnew(int content);
void	ft_listclear(t_data *data);
void	ft_listadd_front(t_data *data, t_lst *new);
void	set_list_max(t_data *data);
void	set_2p(t_lst **p1, t_lst *p2, t_lst **pt1, t_lst *pt2);
int		is_no_empty_line(char *line);
#endif
