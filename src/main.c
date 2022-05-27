/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:42 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/27 18:48:27 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *the_philos, t_main	*life_philo)
{
	t_philo		*aux;

	aux = the_philos;
	if (the_philos->main->philo_n == 1)
	{
		printf("(%d) %d died\n", the_philos->main->die_n + 1, the_philos->phil);
		return ;
	}
	while (life_philo->start_philo < life_philo->philo_n)
	{
		if (pthread_create(&aux->post_socratic, NULL, &routine, aux))
			return ;
		aux = aux->next;
		life_philo->start_philo++;
	}
	life_philo->start_philo = 0;
	aux = the_philos;
	checking(the_philos);
	while (life_philo->start_philo < life_philo->philo_n)
	{
		pthread_join(aux->post_socratic, NULL);
		aux = aux->next;
		life_philo->start_philo++;
	}
}

int	main(int argc, char **argv)
{
	t_main	life_philo;
	t_philo	*the_philos;

	the_philos = malloc(sizeof(t_philo));
	the_philos->next = NULL;
	if (check_the_argc(argc) != 1)
	{
		free(the_philos);
		return (0);
	}
	if (check_the_argv(argv) != 1)
	{
		free(the_philos);
		return (0);
	}
	init_vars(argv, &life_philo);
	init_philos(&the_philos, &life_philo);
	start_philo(the_philos, &life_philo);
	free_philos(&the_philos, &life_philo);
}
