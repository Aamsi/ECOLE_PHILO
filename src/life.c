/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:19:18 by iouali            #+#    #+#             */
/*   Updated: 2022/01/12 21:04:17 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	put_message(philo->id, philo->time_start, "has taken a fork.", philo);
	pthread_mutex_lock(philo->prev_fork);
	put_message(philo->id, philo->time_start, "has taken a fork.", philo);
}

void	take_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_eating);
	philo->last_meal_time = get_time();
	put_message(philo->id, philo->time_start, "is eating.", philo);
	custom_sleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->is_eating);
}

void	take_sleep(t_philo *philo)
{
	put_message(philo->id, philo->time_start, "is sleeping.", philo);
	custom_sleep(philo->time_to_sleep);
}

void    put_down_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(philo->prev_fork);
}

void	*check_died(void *philo)
{
	t_philo		*philos;

	philos = (t_philo *) philo;
	while (1)
	{
		pthread_mutex_lock(&philos->is_eating);
		// printf("limit : %ld\n", get_time() - philos->last_meal_time);
		if (get_time() - philos->last_meal_time > philos->time_to_die)
		{
			pthread_mutex_lock(&g_can_write);
			put_message(philos->id, philos->time_start, "died.", philo);
			pthread_mutex_unlock(&philos->is_eating);
			g_done = 1;
			return (NULL);
		}
		pthread_mutex_unlock(&philos->is_eating);
		// custom_sleep(100);
	}
	return (NULL);
}