/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:01:10 by iouali            #+#    #+#             */
/*   Updated: 2022/01/08 14:09:24 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft_fct()
{
    printf("pid du thread fils = %d\n", getpid());
    while (1);
    return (NULL);
}

int main()
{
    pthread_t thread;

    printf("pid de main = %d\n", (int) getpid());
    pthread_create(&thread, NULL, &ft_fct, NULL);
    while (1);

    return 0;
}