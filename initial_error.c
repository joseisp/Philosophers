/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:40:13 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/13 14:29:27 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_words(char word)
{

	if(!(word >= 48 && word <= 57))
	{
		printf("Error. Please, insert only numbers\n");
		return 0;
	}
	return 1;
}

int	check_the_argv(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (check_words(argv[i][j]) != 1)
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int	check_the_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error. Check the number of arguments\n");
		return 0;
	}
	return 1;
}
