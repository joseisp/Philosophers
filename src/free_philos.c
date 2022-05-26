/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:53:20 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/25 20:42:38 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **the_philos, t_main *life_philo)
{
	t_philo		*current;
	t_philo		*next;
	int			i;

	i = 0;
	current = (*the_philos);
	while (i < life_philo->philo_n)
	{
		if (current->next)
			next = current->next;
		if (current->fork)
			free(current->fork);
		if (current)
			free(current);
		if (next)
			current = next;
		i++;
	}
}
