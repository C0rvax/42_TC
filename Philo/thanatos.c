/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thanatos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:43:57 by aduvilla          #+#    #+#             */
/*   Updated: 2024/05/14 16:07:55 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stop_philo(t_academia *academia)
{
	pthread_mutex_lock(&academia->end_mutex);
	academia->stop = 1;
	pthread_mutex_unlock(&academia->end_mutex);
}

static int	is_dead(t_philo *philo)
{
	if (get_ts() - philo->academia->start_time >= philo->starve_time)
	{
		print_status(philo, "died");
		stop_philo(philo->academia);
		return (1);
	}
	return (0);
}

static int	is_over(t_academia *academia)
{
	int	i;
	int	full;

	i = 0;
	full = 1;
	while (i < academia->nb_philos)
	{
		pthread_mutex_lock(&academia->philo[i]->starve_mutex);
		if (academia->meals_max != -2)
			if (academia->philo[i]->n_meals < academia->meals_max)
				full = 0;
		if (is_dead(academia->philo[i]))
		{
			pthread_mutex_unlock(&academia->philo[i]->starve_mutex);
			return (1);
		}
		pthread_mutex_unlock(&academia->philo[i]->starve_mutex);
		if (full)
		{
			stop_philo(academia);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*thanatos(void *academia)
{
	t_academia	*adm;

	usleep(200);
	adm = (t_academia *)academia;
	if (adm->meals_max == 0)
		return (NULL);
	while (1)
	{
		if (is_over(adm))
			return (NULL);
		usleep(900);
	}
	return (NULL);
}
