/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:03:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/18 15:22:36 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *a, t_data *b)
{
	a->list = NULL;
	a->size = 0;
	a->max = -2147483648;
	a->min = 2147483647;
	b->list = NULL;
	b->size = 0;
	b->max = -2147483648;
	b->min = 2147483647;

}

static void	loop_list(t_lst **a)
{
	t_lst	*buf;

	buf = *a;
	while (buf->next)
		buf = buf->next;
	(*a)->prev = buf;
	buf->next = *a;
}

static void	fill_list(t_data *a, int *buf)
{
	int		i;
	t_lst	*new;

	i = a->size - 1;
	a->list = ft_listnew(buf[i]);
	i--;
	while (i >= 0)
	{
		new = ft_listnew(buf[i]);
		ft_listadd_front(a, new);
		i--;
	}
	loop_list(&a->list);
}

static int	init_list_a(t_data *a, int ac, char **av)
{
	char	**charlist;
	int		*buf;

	if (ac == 2)
	{
		charlist = ft_split(av[1], ' ');
		if (!charlist)
			return (ft_printf("Error\n"), 0);
	}
	else
		charlist = av + 1;
	while (charlist[a->size])
		a->size++;
	buf = check_list(charlist, a->size);
	if (ac == 2)
		ft_freetab(charlist);
	if (!buf)
		return (0);
	fill_list(a, buf);
	free(buf);
	set_list_max(a);
	return (1);
}

int	main(int ac, char **av)
{
//	int		i;
	t_data	a;
	t_data	b;

	if (ac < 2)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (ft_putstr_fd("Error\n", 2), 1);
	init_data(&a, &b);
	if (!init_list_a(&a, ac, av))
		return (1);
	sort_list(&a, &b);
//	print_list(&a);
	if (!u_never_know(&a))
		ft_printf("wrong!\n");
	ft_listclear(&a);
	/*
	i = 0;
	while (i < a.size)
	{
		ft_printf("a[%d] = %d\n", i, a.list->content);
		a.list = a.list->next;
		i++;
	}
	*/
	return (0);
}
