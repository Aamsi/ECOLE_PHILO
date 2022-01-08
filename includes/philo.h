/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:56:39 by iouali            #+#    #+#             */
/*   Updated: 2022/01/08 14:27:48 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_arguments
{
    int nb_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_of_eating;
}               t_arguments;

#endif
