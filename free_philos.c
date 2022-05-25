/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:53:20 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/25 00:54:31 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **the_philos)
{
	t_philo		*current;
	t_philo		*next;
	int i;

	i = 0;
	current = (*the_philos);
	while (i < (*the_philos)->main->philo_n)
	{
		next = current->next;
		free(current->fork);
		//free (current);
		current = next;
		i++;
	}
	i = 0;
	current = (*the_philos);
	while (i < (*the_philos)->main->philo_n)
	{
		next = current->next;
		free (current);
		current = next;
		i++;
	}
}
