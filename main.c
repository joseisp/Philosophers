/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:42 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/23 17:29:37 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t teste;

void	eating(t_philo *t_philos)
{
	pthread_mutex_lock(t_philos->fork);
	printf("[%ld] %d has taken a fork\n", time_from_start_in_ms(), t_philos->phil);
	pthread_mutex_lock(t_philos->next->fork);
	printf("[%ld] %d has taken a fork\n", time_from_start_in_ms(), t_philos->phil);
	printf("[%ld] %d is eating\n", time_from_start_in_ms(), t_philos->phil);
	usleep(t_philos->main->eat_n * 1000);
	pthread_mutex_unlock(t_philos->fork);
	pthread_mutex_unlock(t_philos->next->fork);
}

void*	routine(void *arg)
{
	t_philo *the_philos;

	the_philos = (t_philo *)arg;
	//printf("--%d--\n", t_philos->phil);
	if (the_philos->phil % 2 == 0)
		usleep(50);
	eating(the_philos);
	printf("[%ld] %d is sleeping\n", time_from_start_in_ms(), the_philos->phil);
	usleep(the_philos->main->sleep_n * 1000);
	printf("[%ld] %d is thinking\n", time_from_start_in_ms(), the_philos->phil);
	// if (the_philos->phil % 2 == 1)
	// {
	// 	eating(the_philos);
	// 	printf("[%ld] %d is sleeping\n", time_from_start_in_ms(), the_philos->phil);
	// 	usleep(the_philos->main->sleep_n * 1000);
	// 	printf("[%ld] %d is thinking\n", time_from_start_in_ms(), the_philos->phil);
	// }
}

void	start_philo(t_philo *the_philos, t_main	*life_philo)
{
	pthread_t post_socratic[life_philo->philo_n];
	t_philo *aux;
	int i;

	i = 0;
	aux = the_philos;
	time_from_start_in_ms();
	while(1)
	{
		usleep(10);
		if(pthread_create(&post_socratic[i], NULL, &routine, the_philos))
			return ;
		pthread_detach(post_socratic[i]);
		the_philos = the_philos->next;
		if (i >= the_philos->main->philo_n)
			i = 0;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_main	life_philo;
	t_philo *the_philos;
	the_philos = malloc(sizeof(t_philo));
	the_philos->next = NULL;
	pthread_mutex_init(&teste, NULL);

	if (check_the_argc(argc) != 1)
	{
		free_philos(&the_philos);
		return 0;
	}
	if (check_the_argv(argv) != 1)
	{
		free_philos(&the_philos);
		return 0;
	}
	init_vars(argv, &life_philo);
	init_philos(&the_philos, &life_philo);
	start_philo(the_philos, &life_philo);
	free_philos(&the_philos);
}
