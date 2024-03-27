/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:35:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/27 14:21:16 by aduvilla         ###   ########.fr       */
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
	pthread_t		*ending;
	time_t			t_to_die;
	time_t			t_to_eat;
	time_t			t_to_sleep;
	int				n_meals;
	pthread_mutex_t	l_starve;
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
