/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:53:08 by aduvilla          #+#    #+#             */
/*   Updated: 2024/05/13 17:38:16 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stop_philo(t_academia *academia)
{
	pthread_mutex_lock(&academia->stop_lock);
	academia->stop = 1;
	pthread_mutex_unlock(&academia->stop_lock);
}

static int	is_dead(t_philo *philo)
{
	if (get_ts() >= philo->starve_time)
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
	int	finish;

	i = 0;
	finish = 1;
	while (i < academia->nb_philos)
	{
		pthread_mutex_lock(&academia->philo[i]->starve_lock);
		if (academia->meals_max != -2)
		{
			if (academia->philo[i]->n_meals < academia->meals_max)
				finish = 0;
		}
		if (is_dead(academia->philo[i]))
		{
			pthread_mutex_unlock(&academia->philo[i]->starve_lock);
			return (1);
		}
		pthread_mutex_unlock(&academia->philo[i]->starve_lock);
		if (finish)
		{
			stop_philo(academia);
			return (1);
		}
		i++;
	}
	return (0);
}

void	than(t_academia *academia)
{
	if (academia->meals_max == 0)
		return ;
	while (1)
	{
		if (is_over(academia))
			return ;
		usleep(900);
	}
}

int	main(int ac, char **av)
{
	t_academia	academia;
	char		*use;
	char		*use2;

	use = "./philo [nb of philosophers] [time to die] [time to eat]";
	use2 = "[time to sleep] [number of meals]";
	if (ac != 5 || ac != 6)
		return (print_error("usage :", use, use2, 1));
	if (init_academia(&academia, ac, av))
	{
		free(academia.philo);
		return (1);
	}
	if (init_philo(&academia))
	{
		clean_exit(&academia);
		return (1);
	}
	if (pthread_create(&academia.thanatos, NULL, &than, academia))
	{
		clean_exit(&academia);
		return (1);
	}
}
