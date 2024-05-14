/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:53:37 by aduvilla          #+#    #+#             */
/*   Updated: 2024/05/14 15:53:52 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_solo(t_philo *philo)
{
	pthread_mutex_lock(&philo->selfork_mutex);
	print_status(philo, "has taken a fork");
	usleep(philo->academia->die_time * 1000);
	print_status(philo, "died");
	pthread_mutex_unlock(&philo->selfork_mutex);
}

static void	philo_eat_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->selfork_mutex);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->taxfork_mutex);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->starve_mutex);
	philo->starve_time = get_ts() + philo->academia->die_time;
	philo->n_meals++;
	pthread_mutex_unlock(&philo->starve_mutex);
	usleep(philo->academia->eat_time * 1000);
	pthread_mutex_unlock(&philo->selfork_mutex);
	pthread_mutex_unlock(philo->taxfork_mutex);
	print_status(philo, "is sleeping");
	usleep(philo->academia->sleep_time * 1000);
	print_status(philo, "is thinking");
}

void	*philo(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	if (philo->academia->nb_philos == 1)
		philo_solo(philo);
	else
	{
		pthread_mutex_lock(&philo->starve_mutex);
		philo->starve_time = get_ts() + philo->academia->die_time;
		pthread_mutex_unlock(&philo->starve_mutex);
		if (philo->id % 2 == 0)
			usleep(philo->academia->eat_time * 100);
		while (philos_alive(philo->academia))
			philo_eat_sleep_think(philo);
	}
	return (NULL);
}
