/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:42 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/13 16:15:28 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_vars(char **argv, t_main *life_philo) // filo, time to die, time to eat, time to sleep, number of meals
{
	life_philo->eat = argv[]
}

int main(int argc, char **argv)
{
	t_main life_philo;

	if (check_the_argc(argc) != 1)
		return 0;
	if (check_the_argv(argv) != 1)
		return 0;
	init_vars(argv, &life_philo);
}
