/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:42 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/25 01:55:32 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void checking(t_philo *the_philos);


void	print_analyzer(t_philo *phils, int selector)
{
	if (selector == EATING && phils->main->dead == 0 && phils->main->no_hungry == 0)
		printf("(%ld) %d -is eating-\n", timing(), phils->phil);
	else if (selector == FORK && phils->main->dead == 0 && phils->main->no_hungry == 0)
		printf("(%ld) %d has taken a fork\n", timing(), phils->phil);
	else if (selector == SLEEPING && phils->main->dead == 0 && phils->main->no_hungry == 0)
		printf("(%ld) %d is sleeping\n", timing(), phils->phil);
	else if (selector == THINKING && phils->main->dead == 0 && phils->main->no_hungry == 0)
		printf("(%ld) %d is thinking\n", timing(), phils->phil);
}

void	eating(t_philo *t_philos)
{
	pthread_mutex_lock(t_philos->fork);
	pthread_mutex_lock(t_philos->next->fork);
	print_analyzer(t_philos, FORK);
	print_analyzer(t_philos, FORK);
	print_analyzer(t_philos, EATING);
	t_philos->time_to_eat = timing();
	usleep(t_philos->main->eat_n * 1000);
	t_philos->quantity_meal++;
	pthread_mutex_unlock(t_philos->fork);
	pthread_mutex_unlock(t_philos->next->fork);
}

void*	routine(void *arg)
{
	t_philo *the_philos;

	the_philos = (t_philo *)arg;
	while(1 && the_philos->main->freedom == 0)
	{
		if (the_philos->phil % 2 == 0)
			usleep(50);
		eating(the_philos);
		the_philos->main->ate_n++;
		print_analyzer(the_philos, SLEEPING);
		usleep(the_philos->main->sleep_n * 1000);
		print_analyzer(the_philos, THINKING);
	}
}

void	start_philo(t_philo *the_philos, t_main	*life_philo)
{
	pthread_t post_socratic[life_philo->philo_n];
	t_philo *aux;
	int i;

	i = 0;
	aux = the_philos;
	timing();
	if (the_philos->main->philo_n == 1)
	{
		printf("(%ld) %d died\n", timing(),the_philos->phil);
		return ;
	}
	while(i < life_philo->philo_n)
	{
		if(pthread_create(&post_socratic[i], NULL, &routine, aux))
			return ;
		//pthread_detach(post_socratic[i]);
		aux = aux->next;
		i++;
	}
	i = 0;
	checking(the_philos);
	while (i < life_philo->philo_n)
	{
		pthread_join(post_socratic[i], NULL);
		i++;
	}
}

void checking(t_philo *the_philos)
{
	t_philo *aux;

	aux = the_philos;
	while(1)
	{
		if ((timing() - aux->time_to_eat) > aux->main->die_n)
		{
			//usleep(500);
			aux->main->dead++;
			printf("(%ld) %d died \n", timing(),aux->phil);
			the_philos->main->freedom  = 1;
			return ;
		}
		if (aux->main->ate_n == (aux->main->meals_n * aux->main->philo_n) && \
		aux->main->meals_n != -1)
		{
			usleep(20);
			the_philos->main->no_hungry++;
			printf("All philosophers have been fed\n");
			the_philos->main->freedom = 1;
			return ;
		}
		aux = aux->next;
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
