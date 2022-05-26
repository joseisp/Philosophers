/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:54:43 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/25 21:17:16 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_vars(char **argv, t_main *life_philo)
{
	life_philo->philo_n = ft_atoi(argv[1]);
	life_philo->die_n = ft_atoi(argv[2]);
	life_philo->eat_n = ft_atoi(argv[3]);
	life_philo->sleep_n = ft_atoi(argv[4]);
	life_philo->ate_n = 0;
	life_philo->last_meal = 0;
	life_philo->dead = 0;
	life_philo->freedom = 0;
	life_philo->init_philos = 0;
	life_philo->start_philo = 0;
	if (argv[5])
		life_philo->meals_n = ft_atoi(argv[5]);
	else
		life_philo->meals_n = -1;
}

// void	init_philos_aux(t_philo **the_philos, t_philo *aux)
// {

// }

void	init_philos(t_philo **the_philos, t_main *life_philo)
{
	t_philo	*aux_head;
	t_philo	*aux;

	aux_head = (*the_philos);
	while (life_philo->init_philos < life_philo->philo_n)
	{
		aux = (t_philo *)malloc(sizeof(t_philo));
		aux->phil = life_philo->init_philos + 1;
		aux->time_to_eat = 0;
		aux->quantity_meal = 1;
		aux->post_socratic = 0;
		aux->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(aux->fork, NULL);
		aux->next = NULL;
		(*the_philos)->next = aux;
		(*the_philos) = (*the_philos)->next;
		(*the_philos)->main = life_philo;
		if (life_philo->init_philos == 0)
			free(aux_head);
		if (life_philo->init_philos == 0)
			aux_head = (*the_philos);
		life_philo->init_philos++;
	}
	(*the_philos)->next = aux_head;
	(*the_philos) = aux_head;
}
