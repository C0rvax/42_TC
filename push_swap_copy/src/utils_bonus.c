/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:16:26 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/26 13:41:42 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_list_max(t_data *data)
{
	int		i;
	t_lst	*buf;

	i = 0;
	data->max = -2147483648;
	data->min = 2147483647;
	buf = data->list;
	if (buf->content > data->max)
		data->max = buf->content;
	if (buf->content < data->min)
		data->min = buf->content;
	while (i < data->size && data->size > 1)
	{
		if (buf->content > data->max)
			data->max = buf->content;
		if (buf->content < data->min)
			data->min = buf->content;
		buf = buf->next;
		i++;
	}
}

void	set_2p(t_lst **p1, t_lst *p2, t_lst **pt1, t_lst *pt2)
{
	*p1 = p2;
	*pt1 = pt2;
}

int	u_never_know(t_data *a)
{
	int		i;
	t_lst	*list;

	i = 0;
	list = a->list;
	while (i < a->size - 1)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

char	*get_all_lines(int fd)
{
	char	*buf;
	char	*line;
	char	*copy;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		copy = line;
		line = ft_strjoin(line, buf);
		if (!line)
			return (close(fd), free(buf), free(copy), NULL);
		free(copy);
		free(buf);
	}
	return (line);
}
/*
void	print_list(t_data *data)
{
	int	i;

	i = 0;
	if (data->size == 1)
		ft_printf("a[0] = %d\n", data->list->content);
	while (i < data->size && data->size > 1)
	{
		ft_printf("a[%d] = %d\n", i, data->list->content);
		data->list = data->list->next;
		i++;
	}
}
*/
