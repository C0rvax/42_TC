/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:42:35 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/15 13:44:44 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttstr_fd(char **tab, int fd)
{
	unsigned int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
