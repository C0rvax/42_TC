/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:37:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/07 22:51:17 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
}		t_lst;

typedef struct stack_s
{
	int		*stack;
	int		size;
	int		max;
}			t_stack;

typedef struct data_s
{
	t_stack	*a;
	t_stack	*b;
}			t_data;

int		*check_list(char **av, int size);
t_lst	*ft_listnew(int content);
t_lst	*ft_listlast(t_lst *lst);
void	ft_listadd_back(t_lst **lst, t_lst *new);
void	ft_listclear(t_lst **lst);
void	ft_listadd_front(t_lst **lst, t_lst *new);
#endif
