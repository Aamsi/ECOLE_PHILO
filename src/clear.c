/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:19:35 by iouali            #+#    #+#             */
/*   Updated: 2022/01/12 20:57:36 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_of_philos)
	{
		pthread_mutex_destroy(&philos[i].is_eating);
		pthread_mutex_destroy(&philos[i].fork);
		i++;
	}
	free(philos);
}