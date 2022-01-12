/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:39:05 by iouali            #+#    #+#             */
/*   Updated: 2022/01/12 21:01:42 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philos(int argc, char **argv)
{
	int		i;
	t_philo	*philos;
	t_control	control;

	philos = ft_calloc(sizeof(t_philo), ft_atoi(argv[1]));
	if (!philos)
		return (NULL);
	g_done = 0;
	pthread_mutex_init(&g_can_write, NULL);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&philos[i].fork, NULL);
		pthread_mutex_init(&philos[i].is_eating, NULL);
		philos[i].control = &control;
		philos[i].id = i;
		philos[i].time_start = get_time();
		philos[i].last_meal_time = get_time();
		if (i == 0)
			philos[i].prev_fork = NULL;
		else
			philos[i].prev_fork = &philos[i - 1].fork;
		philos[i].nb_of_philos = ft_atoi(argv[1]);
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		if (argc == 6)
			philos[i].nb_of_eating = ft_atoi(argv[5]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		i++;
	}
	philos[0].prev_fork = &(philos[i - 1].fork);
	return (philos);
}
