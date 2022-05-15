/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:42 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/15 05:50:44 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_vars(char **argv, t_main *life_philo) // filo, time to die, time to eat, time to sleep, number of meals
{
	life_philo->philo_n = ft_atoi(argv[1]);
	life_philo->die_n = ft_atoi(argv[2]);
	life_philo->eat_n = ft_atoi(argv[3]);
	life_philo->sleep_n = ft_atoi(argv[4]);
	if (argv[5])
		life_philo->meals_n = ft_atoi(argv[5]);
}

void	init_philos(t_philo *the_philos, t_main *life_philo)
{
	int i;
	t_philo *aux_head;
	t_philo *aux;

	i = 0;
	aux_head = the_philos;
	while(i < life_philo->philo_n)
	{
		aux = malloc(sizeof(t_philo));
		aux->philosopher = i + 1;
		aux->next = NULL;
		the_philos->next = aux;
		the_philos = the_philos->next;
		i++;
	}
	the_philos = aux_head;
}

int main(int argc, char **argv)
{
	t_main	life_philo;
	t_philo *the_philos;
	the_philos = malloc(sizeof(t_philo));
	the_philos->next = NULL;

	if (check_the_argc(argc) != 1)
		return 0;
	if (check_the_argv(argv) != 1)
		return 0;
	init_vars(argv, &life_philo);
	init_philos(the_philos, &life_philo);
}
