/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:01:10 by iouali            #+#    #+#             */
/*   Updated: 2022/01/19 19:51:35 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *philo)
{
	t_philo		*philos;
	pthread_t	dead_thread;

	philos = (t_philo *) philo;
	pthread_create(&dead_thread, NULL, &check_died, philos);
	pthread_detach(dead_thread);
	if (philos->id % 2 == 0)
		custom_sleep(100);
	while (1)
	{
		take_forks(philos);
		take_meal(philos);
		put_down_forks(philos);
		take_sleep(philos);
		put_message(philos->id, philos->time_start, "is thinking.", philo);
	}
	return (NULL);
}

void	philo_threads(t_philo *philos)
{
	int				i;
	pthread_t		philo_thread;
	pthread_mutex_t	lock;
	pthread_mutex_t can_write;

	pthread_mutex_init(&lock, NULL);
	pthread_mutex_init(&can_write, NULL);
	pthread_mutex_lock(&lock);
	i = 0;
	while (i < philos[0].nb_of_philos)
	{
		philos[i].lock = &lock;
		philos[i].can_write = &can_write;
		pthread_create(&philo_thread, NULL, &thread, &philos[i]);
		pthread_detach(philo_thread);
		custom_sleep(15);
		i++;
	}
	pthread_mutex_lock(&lock);
	free(philos);
	clear_mutex(philos);
}

int main(int argc, char **argv)
{
	t_philo	*philos;

	if (ft_atoi(argv[1]) == 0)
		return (1);
	philos = init_philos(argc, argv);
	if (!philos)
		return (-1);
	philo_threads(philos);
    return (0);
}
