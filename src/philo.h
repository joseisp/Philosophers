/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:44:35 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/27 11:55:38 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define EATING 3
# define FORK 4
# define SLEEPING 1
# define THINKING 2
# define DEAD 5
# define FED 6

typedef struct s_main
{
	int	philo_n;
	int	sleep_n;
	int	die_n;
	int	eat_n;
	int	meals_n;
	int	ate_n;
	int	last_meal;
	int	dead;
	int	freedom;
	int	init_philos;
	int	start_philo;
	pthread_mutex_t	*prints;
}t_main;

typedef struct s_philo
{
	int				phil;
	int				quantity_meal;
	int				time_to_eat;
	pthread_mutex_t	*fork;
	pthread_t		post_socratic;
	t_main			*main;
	struct s_philo	*next;
	int				i;
	int				sum_routine;
}t_philo;

//error functions

int		check_the_argc(int argc);
int		check_the_argv(char **argv);

// utils

int		ft_atoi(const char	*str);
int		timing(void);

// init and insert

void	init_vars(char **argv, t_main *life_philo);
void	init_philos(t_philo **the_philos, t_main *life_philo);

//free

void	free_philos(t_philo **the_philos, t_main *life_philo);

//monitoring

void	checking(t_philo *the_philos);

//routine

void	print_analyzer(t_philo *phils, int selector);
void	eating(t_philo *t_philos);
void	*routine(void *arg);
#endif
