/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:54:43 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/24 17:52:31 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_vars(char **argv, t_main *life_philo) // filo, time to die, time to eat, time to sleep, number of meals
{
	life_philo->philo_n = ft_atoi(argv[1]);
	life_philo->die_n = ft_atoi(argv[2]);
	life_philo->eat_n = ft_atoi(argv[3]);
	life_philo->sleep_n = ft_atoi(argv[4]);
	life_philo->ate_n = 0;
	if (argv[5])
		life_philo->meals_n = ft_atoi(argv[5]);
}

void	init_philos(t_philo **the_philos, t_main *life_philo)
{
	int i;
	t_philo *aux_head;
	t_philo *aux;

	i = 0;
	aux_head = (*the_philos);
	while(i < life_philo->philo_n)
	{
		aux = (t_philo* )malloc(sizeof(t_philo));
		aux->phil = i + 1;
		aux->time_to_eat = 0;
		aux->quantity_meal = 1;
		aux->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(aux->fork, NULL);
		aux->next = NULL;
		(*the_philos)->next = aux;
		(*the_philos) = (*the_philos)->next;
		(*the_philos)->main = life_philo;
		if (i == 0)
			aux_head = (*the_philos);
		i++;
	}
	(*the_philos)->next = aux_head;
	(*the_philos) = aux_head;
}
