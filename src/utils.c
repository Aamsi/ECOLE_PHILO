/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:39:45 by iouali            #+#    #+#             */
/*   Updated: 2022/01/19 19:20:11 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	custom_sleep(int time)
{
	long	time_now;

	time_now = get_time();
	while (get_time() < time_now + time)
		usleep(1);
}

void	put_message(int id, long time_start, char *message, t_philo *philo)
{
	long	time_delta;

	pthread_mutex_lock(philo->can_write);
	time_delta = get_time() - time_start;
	printf("%ld ms - Philo %d %s\n", time_delta, id + 1, message);
	pthread_mutex_unlock(philo->can_write);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n')
		return (1);
	return (0);
}

long long	ft_atoi(char *nptr)
{
	size_t			i;
	unsigned char	*tmp_nptr;
	long long		sign;
	long long		result;

	tmp_nptr = (unsigned char *)nptr;
	sign = 1;
	result = 0;
	i = 0;
	while (is_space(tmp_nptr[i]))
		i++;
	if (tmp_nptr[i] == '-' || tmp_nptr[i] == '+')
	{
		if (tmp_nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (tmp_nptr[i] >= '0' && tmp_nptr[i] <= '9')
	{
		result = (result * 10) + (tmp_nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*to_return;
	size_t			i;

	to_return = malloc(size * nmemb);
	if (!to_return)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		to_return[i] = 0;
		i++;
	}
	return (to_return);
}
