/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:01:10 by iouali            #+#    #+#             */
/*   Updated: 2022/01/10 19:19:16 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *philo)
{
	t_philo		*philos;
	pthread_t	dead_thread;

	philos = (t_philo *) philo;
	usleep(100);
	pthread_create(&dead_thread, NULL, &check_died, philos);
	while (philos->control->done == 0)
	{
		take_forks(philos);
		put_down_forks(philos);
		take_meal(philos);
		take_sleep(philos);
		put_message(philos->id, philos->time_start, "is thinking.", philo);
	}
	return (NULL);
}

void	philo_threads(t_philo *philos)
{
	int				i;
	pthread_t		philo_thread;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	can_write;

	pthread_mutex_init(&is_eating, NULL);
	pthread_mutex_init(&can_write, NULL);
	i = 0;
	while (i < philos[0].nb_of_philos)
	{
		philos[i].can_write = can_write;
		philos[i].is_eating = is_eating;
		pthread_create(&philo_thread, NULL, &thread, &philos[i]);
		usleep(35);
		i++;
	}
	if (philos[0].nb_of_philos > 1)
		pthread_join(philo_thread, NULL);
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
