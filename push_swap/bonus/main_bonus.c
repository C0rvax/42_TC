/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:03:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/01 14:02:17 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	fill_list(t_data *a, int *buf)
{
	int		i;
	t_lst	*new;

	i = a->size - 1;
	a->list = ft_listnew(buf[i]);
	if (!a->list)
		return (0);
	i--;
	while (i >= 0)
	{
		new = ft_listnew(buf[i]);
		if (!new)
			return (ft_listclear(a), 0);
		ft_listadd_front(a, new);
		i--;
	}
	loop_list(&a->list);
	return (1);
}

static int	init_list_a(t_data *a, int ac, char **av)
{
	char	**charlist;
	int		*buf;

	if (ac == 2)
	{
		charlist = ft_split(av[1], ' ');
		if (!charlist)
			return (ft_putstr_fd("Error\n", 2), 0);
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
	if (!fill_list(a, buf))
		return (free(buf), 0);
	free(buf);
	set_list_max(a);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	a;
	t_data	b;

	if (ac < 2)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (ft_putstr_fd("Error\n", 2), 1);
	init_data(&a, &b);
	if (!init_list_a(&a, ac, av))
		return (1);
	if (instructions(&a, &b) < 0)
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (u_never_know(&a, &b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	if (a.list)
		ft_listclear(&a);
	if (b.list)
		ft_listclear(&b);
	return (0);
}
