/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:09:22 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/27 11:11:55 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	exec_swap(int p, t_data *data)
{
	int		buf;

	buf = data->list->content;
	data->list->content = data->list->next->content;
	data->list->next->content = buf;
	return (p);
}

static t_lst	*extract_from_list(t_data *data)
{
	t_lst	*buf_n;
	t_lst	*buf_p;
	t_lst	*node;

	node = data->list;
	if (data->size == 1)
		data->list = NULL;
	else
	{
		buf_n = data->list->next;
		buf_p = data->list->prev;
		data->list = buf_n;
		set_2p(&node->next, NULL, &node->prev, NULL);
		if (data->size > 2)
		{
			buf_n->prev = buf_p;
			buf_p->next = buf_n;
		}
		if (data->size == 2)
			set_2p(&buf_n->next, NULL, &buf_n->prev, NULL);
	}
	data->size--;
	return (node);
}

int	exec_push(int p, t_data *in, t_data *out)
{
	t_lst	*buf_p;
	t_lst	*node;

	node = extract_from_list(in);
	if ((node->content == in->max || node->content == in->min) && in->size > 0)
		set_list_max(in);
	if (out->size == 1)
	{
		set_2p(&out->list->prev, node, &out->list->next, node);
		set_2p(&node->prev, out->list, &node->next, out->list);
	}
	else if (out->size > 1)
	{
		buf_p = out->list->prev;
		set_2p(&buf_p->next, node, &out->list->prev, node);
		set_2p(&node->next, out->list, &node->prev, buf_p);
	}
	out->list = node;
	out->size++;
	if (node->content > out->max || node->content < out->min)
		set_list_max(out);
	return (p);
}

static int	exec_rotate(int p, t_lst **list)
{
	if (p == 3)
		*list = (*list)->next;
	else
		*list = (*list)->prev;
	return (p);
}

char	**ft_getcmd(void)
{
	char	**cmd;
	char	*line;

	line = "sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr";
	cmd = ft_split(line, ';');
	if (!cmd)
		return (NULL);
	return (cmd);
}

int		check_instructions(char **cmd, char **instructions)
{
	int		i;
	int		j;
	int		count;
	int		len;

	i = 0;
	count = 0;
	while (instructions[i])
	{
		j = 0;
		len = ft_strlen(instructions[i]);
		while (cmd[j])
		{
			if (!ft_strncmp(instructions[i], cmd[j], len))
				count++;
			j++;
		}
		i++;
	}
	if (count != i)
		return (0);
	else
		return (1);
}

int		instructions(t_data *a, t_data *b)
{
	int		i;
	char	**cmd;
	char	**instructions;

	cmd = ft_getcmd();
	if (!cmd)
		return (0);
	instructions = ft_get_instruc(0);
}

char	**ft_get_instruc(int fd)
{
	char	*line;
	char	**instructions;

	line = get_all_lines(fd);
	if (!line)
		return (ft_putstr_fd("Error\n", 2), NULL);
	instructions = ft_split(line, '\n');
	if (!instructions)
		return (free(line), ft_putstr_fd("Error\n", 2), NULL);
}
void	exec_instructions(t_data *a, t_data *b)
{
	char	*line;
	char	**array;
	int		i;

	line = get_all_lines(0);
	if (!line)
		ft_putstr_fd("Error\n", 2);
	array = ft_split(line, '\n');
	if (!array)
		ft_putstr_fd("Error\n", 2);
	free(line);
	i = 0;
	while (array[i])
	{
		if (!ft_strncmp(array[i], "ra", ft_strlen(array[i])))
			exec_rotate(3, &a->list);
		if (!ft_strncmp(array[i], "rb", ft_strlen(array[i])))
			exec_rotate(3, &b->list);
		if (!ft_strncmp(array[i], "pa", ft_strlen(array[i])))
			exec_push(3, b, a);
		if (!ft_strncmp(array[i], "pb", ft_strlen(array[i])))
			exec_push(3, a, b);
		if (!ft_strncmp(array[i], "rr", ft_strlen(array[i])))
		{
			exec_rotate(3, &b->list);
			exec_rotate(3, &a->list);
		}
		if (!ft_strncmp(array[i], "rrr", ft_strlen(array[i])))
		{
			exec_rotate(4, &b->list);
			exec_rotate(4, &a->list);
		}
		if (!ft_strncmp(array[i], "rra", ft_strlen(array[i])))
			exec_rotate(4, &a->list);
		if (!ft_strncmp(array[i], "rrb", ft_strlen(array[i])))
			exec_rotate(4, &b->list);
		if (!ft_strncmp(array[i], "sa", ft_strlen(array[i])))
			exec_swap(3, a);
		if (!ft_strncmp(array[i], "sb", ft_strlen(array[i])))
			exec_swap(3, b);
		i++;
	}
}
