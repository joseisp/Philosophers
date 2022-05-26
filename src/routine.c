/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:46:13 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/25 21:20:25 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_analyzer(t_philo *phils, int selector)
{
	if (selector == EATING && phils->main->dead == 0)
		printf("(%d) %d is eating\n", timing(), phils->phil);
	else if (selector == FORK && phils->main->dead == 0)
		printf("(%d) %d has taken a fork\n", timing(), phils->phil);
	else if (selector == SLEEPING && phils->main->dead == 0)
		printf("(%d) %d is sleeping\n", timing(), phils->phil);
	else if (selector == THINKING && phils->main->dead == 0)
		printf("(%d) %d is thinking\n", timing(), phils->phil);
}

void	eating(t_philo *t_philos)
{
	pthread_mutex_lock(t_philos->fork);
	pthread_mutex_lock(t_philos->next->fork);
	print_analyzer(t_philos, FORK);
	print_analyzer(t_philos, FORK);
	print_analyzer(t_philos, EATING);
	t_philos->time_to_eat = timing() - 3;
	usleep(t_philos->main->eat_n * 1000);
	pthread_mutex_unlock(t_philos->fork);
	pthread_mutex_unlock(t_philos->next->fork);
}

void	*routine(void *arg)
{
	t_philo	*the_philos;

	the_philos = (t_philo *)arg;
	while (1 && the_philos->main->dead == 0)
	{
		if (the_philos->phil % 2 == 0)
			usleep(50);
		eating(the_philos);
		the_philos->main->ate_n++;
		print_analyzer(the_philos, SLEEPING);
		usleep(the_philos->main->sleep_n * 1000);
		print_analyzer(the_philos, THINKING);
	}
	return ((void *)arg);
}
