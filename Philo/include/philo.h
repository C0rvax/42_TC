/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:35:54 by aduvilla          #+#    #+#             */
/*   Updated: 2024/05/13 17:36:46 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_academia
{
	int				nb_philos;
	time_t			die_time;
	time_t			eat_time;
	time_t			sleep_time;
	int				meals_max;
	int				stop;
	pthread_mutex_t	stop_lock;
	time_t			start_time;
	pthread_t		thanatos;
	pthread_mutex_t	print;
	struct s_philo	**philo;
}		t_academia;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	time_t				starve_time;
	int					n_meals;
	pthread_mutex_t		starve_lock;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		*r_fork;
	struct s_academia	*academia;
}		t_philo;

int		print_error(char *s1, char *s2, char *s3, int status);
time_t	get_ts(void);
int		phi_atoi(char *arg);
int		init(t_academia *academia, int ac, char **av);
int		init_academia(t_academia *academia, int ac, char **av);
int		init_philo(t_academia *adm);
void	print_status(t_philo *philo, char *s);

#endif
