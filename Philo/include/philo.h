/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:35:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/05/13 10:05:56 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_academia
{
	int				nb_philos;
	int				n_meals;
	time_t			die_time;
	time_t			eat_time;
	time_t			sleep_time;
	pthread_t		thanatos;
	pthread_mutex_t	l_starve;
	pthread_mutex_t	print;
	struct s_philo	**philo;
}		t_academia;

typedef struct	s_philo
{
	pthread_t			thread;
	int					id;
	time_t				starve_time;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		*r_fork;
	struct s_academia	*academia;
}		t_philo;

#endif
