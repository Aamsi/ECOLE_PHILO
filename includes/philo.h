/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:56:39 by iouali            #+#    #+#             */
/*   Updated: 2022/01/10 19:06:05 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_control
{
    int done;
}               t_control;

typedef struct s_philo
{
    int		nb_of_philos;
    int		time_to_die;
    int		time_to_eat;
    int		time_to_sleep;
    int		nb_of_eating;
	long	time_start;
	int		id;
	long	last_meal_time;
    pthread_mutex_t	*prev_fork;
    pthread_mutex_t is_eating;
    pthread_mutex_t	fork;
	pthread_mutex_t	finished;
    pthread_mutex_t can_write;
    t_control       *control;
}               t_philo;

long long	ft_atoi(char *nptr);
void		put_message(int id, long time_start, char *message, t_philo *philo);
void		*ft_calloc(size_t nmemb, size_t size);
long		get_time(void);
t_philo		*init_philos(int argc, char **argv);
void		take_forks(t_philo *philo);
void		take_meal(t_philo *philo);
void		take_sleep(t_philo *philo);
void        put_down_forks(t_philo *philo);
void        print_debug(t_philo *philos);
void	    *check_died(void *philo);
void	    custom_sleep(int time);


#endif
