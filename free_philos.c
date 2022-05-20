/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:53:20 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/19 20:10:40 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **the_philos)
{
	t_philo		*current;
	t_philo		*next;

	current = (*the_philos);
	while (current != NULL)
	{
		next = current->next;
		free(current->fork);
		free (current);
		current = next;
	}
}
