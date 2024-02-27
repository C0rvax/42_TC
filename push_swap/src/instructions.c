/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:58:24 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/27 12:25:52 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	**ft_getcmd(void)
{
	char	**cmd;
	char	*line;

	line = "sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr";
	cmd = ft_split(line, ';');
	if (!cmd)
		return (NULL);
	return (cmd);
}

static int	check_instructions(char **cmd, char **instructions)
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

static char	**ft_get_instruc(int fd)
{
	char	*line;
	char	**instructions;

	line = get_all_lines(fd);
	if (!line)
		return (ft_putstr_fd("Error\n", 2), NULL);
	if (!is_no_empty_line(line))
		return (free(line), ft_putstr_fd("Error\n", 2), NULL);
	instructions = ft_split(line, '\n');
	free(line);
	if (!instructions)
		return (ft_putstr_fd("Error\n", 2), NULL);
	return (instructions);
}

int	instructions(t_data *a, t_data *b)
{
	int		i;
	char	**cmd;
	char	**instructions;

	cmd = ft_getcmd();
	if (!cmd)
		return (0);
	instructions = ft_get_instruc(0);
	if (!instructions)
		return (ft_freetab(cmd), 0);
	if (!check_instructions(cmd, instructions))
		return (ft_freetab(cmd), ft_freetab(instructions), 0);
	if (!exec_instructions(a, b, cmd, instructions))
		return (ft_freetab(cmd), ft_freetab(instructions), 0);
	ft_freetab(cmd);
	ft_freetab(instructions);
	return (1);
}
