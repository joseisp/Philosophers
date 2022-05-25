/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:42 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/25 19:20:19 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void checking(t_philo *the_philos);


void	print_analyzer(t_philo *phils, int selector)
{
	if (selector == EATING && phils->main->dead == 0)
		printf("(%d) %d -is eating-\n", timing(), phils->phil);
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

void*	routine(void *arg)
{
	t_philo *the_philos;

	the_philos = (t_philo *)arg;
	while(1 && the_philos->main->dead == 0)
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

void	start_philo(t_philo *the_philos, t_main	*life_philo)
{
	pthread_t post_socratic[life_philo->philo_n];
	t_philo *aux;
	int i;

	i = 0;
	aux = the_philos;
	if (the_philos->main->philo_n == 1)
	{
		printf("(%d) %d died\n", timing(),the_philos->phil);
		return ;
	}
	while(i < life_philo->philo_n)
	{
		if(pthread_create(&post_socratic[i], NULL, &routine, aux))
			return ;

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
			aux->main->dead++;
			printf("(%d) %d died \n", timing(),aux->phil);
			return ;
		}
		if (aux->main->ate_n >= (aux->main->meals_n * aux->main->philo_n) && \
		aux->main->meals_n != -1)
		{
			aux->main->dead++;
			the_philos->main->freedom++;
			printf("All philosophers have been fed\n");
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
		free(the_philos);
		return 0;
	}
	if (check_the_argv(argv) != 1)
	{
		free(the_philos);
		return 0;
	}
	init_vars(argv, &life_philo);
	init_philos(&the_philos, &life_philo);
	start_philo(the_philos, &life_philo);
	free_philos(&the_philos, &life_philo);
}
