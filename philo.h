
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct s_main
{
	int	philo_n;
	int	sleep_n;
	int	die_n;
	int	eat_n;
	int	meals_n;

}t_main;

typedef struct	s_philo
{
	int				philosopher;
	int				quantity_meal;
	int				time_to_eat;
	t_main			main;
	struct s_philo	*next;

}t_philo;

//error functions

int	check_the_argc(int argc);
int	check_the_argv(char **argv);

// utils

int	ft_atoi(const char	*str);
