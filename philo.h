
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct s_main
{
	int	philo;
	int	sleep_n;
	int	think_n;
	int	eat_n;
	int	meals_n;

}			t_main;

//error functions

int	check_the_argc(int argc);
int	check_the_argv(char **argv);

// utils

int	ft_atoi(const char	*str);
