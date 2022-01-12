/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:01:10 by iouali            #+#    #+#             */
/*   Updated: 2022/01/12 21:05:33 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *philo)
{
	t_philo		*philos;
	pthread_t	dead_thread;

	philos = (t_philo *) philo;
	pthread_create(&dead_thread, NULL, &check_died, philos);
	if (philos->id % 2 == 0)
		usleep(200);
	while (g_done == 0)
	{
		take_forks(philos);
		take_meal(philos);
		put_down_forks(philos);
		take_sleep(philos);
		put_message(philos->id, philos->time_start, "is thinking.", philo);
	}
	pthread_join(dead_thread, NULL);
	return (NULL);
}

void	philo_threads(t_philo *philos)
{
	int				i;
	pthread_t		philo_thread;

	i = 0;
	while (i < philos[0].nb_of_philos)
	{
		pthread_create(&philo_thread, NULL, &thread, &philos[i]);
		usleep(50);
		i++;
	}
	pthread_join(philo_thread, NULL);
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
