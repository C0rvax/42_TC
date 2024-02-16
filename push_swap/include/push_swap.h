/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:37:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/16 17:52:13 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		*check_list(char **av, int size);
void	sort_list(t_data *a, t_data *b);
int		exec_swap(int print, t_data *data);
int		exec_rotate(int print, t_lst **list);
int		exec_reverse(int print, int *stack, int size);
t_lst	*extract_from_list(t_data *data);
int		find_in_a(t_data *a, t_data *b);
int		exec_push(int print, t_data *in, t_data *out);
t_lst	*ft_listnew(int content);
void	ft_listclear(t_data *data);
void	ft_listadd_front(t_data *data, t_lst *new);
void	print_list(t_data *data);
void	set_list_max(t_data *data);
#endif
