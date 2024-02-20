/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:39:43 by aduvilla          #+#    #+#             */
/*   Updated: 2024/01/26 01:56:34 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_where(t_data *data, int i)
{
	int	res;

	res = 0;
	if (data->a[i] < data->minb || data->a[i] > data->maxb)
	{
		res = find_index(data->b, data->maxb);
		return (res);
	}
	else
	{

	}
}
