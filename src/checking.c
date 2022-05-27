/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:43:00 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/27 11:52:45 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checking(t_philo *the_philos)
{
	t_philo	*aux;

	aux = the_philos;
	while (1)
	{
		if ((timing() - aux->time_to_eat) > aux->main->die_n)
		{
			aux->main->dead++;
			print_analyzer(aux, DEAD);
			return ;
		}
		if (aux->main->ate_n >= (aux->main->meals_n * aux->main->philo_n) && \
		aux->main->meals_n != -1)
		{
			aux->main->dead++;
			the_philos->main->freedom++;
			usleep(10);
			printf("All philosophers have been fed\n");
			return ;
		}
		aux = aux->next;
		usleep(50);
	}
}
