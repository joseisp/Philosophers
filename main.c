/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:42 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/19 22:33:41 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	routine(void *arg)
{
	t_philo *t_philos;

	t_philos = (t_philo *)arg;
	if (t_philos)
	{
		if (t_philos->fork)
		{
			pthread_mutex_lock(t_philos->fork);
			printf("oi\n");
			pthread_mutex_unlock(t_philos->fork);
		}
	}
}

void	start_philo(t_philo *the_philos, t_main	*life_philo)
{
	pthread_t post_socratic[life_philo->philo_n];
	int i;

	i = 0;
	printf("Deu boa?%d\n", life_philo->philo_n);
	while(i < life_philo->philo_n)
	{
		pthread_create(&post_socratic[i], NULL, &routine, the_philos);
		//usleep(1000);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_main	life_philo;
	t_philo *the_philos;
	the_philos = malloc(sizeof(t_philo));
	the_philos->next = NULL;

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
