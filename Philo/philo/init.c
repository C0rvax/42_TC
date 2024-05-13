/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:24:02 by aduvilla          #+#    #+#             */
/*   Updated: 2024/05/13 16:51:50 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_academia(t_academia *academia)
{
	if (academia->nb_philos < 0 || academia->die_time < 0
		|| academia->eat_time < 0 || academia->sleep_time < 0
		|| academia->meals_max == -1)
		return (1);
	if (academia->nb_philos > 250)
		return (print_error("usage", ":", "too much philosophers", 1));
	return (0);
}

int	init_academia(t_academia *academia, int ac, char **av)
{
	academia->nb_philos = phi_atoi(av[1]);
	academia->die_time = phi_atoi(av[2]);
	academia->eat_time = phi_atoi(av[3]);
	academia->sleep_time = phi_atoi(av[4]);
	academia->meals_max = -2;
	if (ac > 5)
		academia->meals_max = phi_atoi(av[5]);
	academia->stop = 0;
	academia->start_time = get_ts();
	if (check_academia(academia))
		return (1);
	if (pthread_mutex_init(&academia->print, NULL))
		return (print_error("error", ":", "could not create mutex", 1));
	if (pthread_mutex_init(&academia->stop_lock, NULL))
		return (print_error("error", ":", "could not create mutex", 1));
	academia->philo = malloc(sizeof(t_philo) * academia->nb_philos);
	if (!academia->philo)
		return (print_error("error", ":", "cannot allocate memory", 1));
	return (0);
}

int	init_philo(t_academia *adm)
{
	int	i;

	while (i < adm->nb_philos)
	{
		adm->philo[i] = malloc(sizeof(t_philo) * 1);
		if (!adm->philo[i])
			return (1);
		adm->philo[i]->id = i + 1;
		adm->philo[i]->starve_time = adm->start_time + adm->die_time;
		adm->philo[i]->academia = adm;
		if (pthread_mutex_init(&adm->philo[i]->l_fork, NULL))
			return (print_error("error", ":", "could not create mutex", 1));
		if (pthread_mutex_init(&adm->philo[i]->starve_lock, NULL))
			return (print_error("error", ":", "could not create mutex", 1));
		i++;
	}
}
