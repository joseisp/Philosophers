/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:06:01 by jinacio-          #+#    #+#             */
/*   Updated: 2022/05/25 01:54:58 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_overflow(int num, int c_minus)
{
	unsigned int	nb;

	nb = num;
	if (nb > 2147483648 && c_minus)
		return (0);
	if (nb > 2147483647 && !c_minus)
		return (-1);
	return (1);
}

int	ft_atoi(const char	*str)
{
	int	c_minus;
	int	num;
	int	ret;

	num = 0;
	c_minus = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c_minus = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	ret = ft_check_overflow(num, c_minus);
	if (ret != 1)
		return (ret);
	if (c_minus)
		return (num *= -1);
	return (num);
}

unsigned long	timing(void)
{
	struct timeval			time;
	static unsigned long	init_time = 0;

	gettimeofday(&time, NULL);
	if (init_time == 0)
		init_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - init_time);
}
