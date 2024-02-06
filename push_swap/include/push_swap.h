/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:37:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 21:07:25 by aduvilla         ###   ########.fr       */
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

typedef struct data_s
{
	char	**av;
	int		*a;
	int		*b;
	int		a_max;
	int		b_max;
}			t_data;

int		*check_list(char **av, int size);
t_lst	*ft_listnew(int content);
t_lst	*ft_listlast(t_lst *lst);
void	ft_listadd_back(t_lst **lst, t_lst *new);
void	ft_listclear(t_lst **lst);
void	ft_listadd_front(t_lst **lst, t_lst *new);
#endif
