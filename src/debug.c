#include "philo.h"

void print_debug(t_philo *philos)
{
    int i;

    i = 0;
    while (i < philos[0].nb_of_philos)
    {
        printf("Philosopher id: %d\n", philos[i].id);
        printf("Nb of philos: %d\n", philos[i].nb_of_philos);
        printf("Time to die: %d ms\n", philos[i].time_to_die);
        printf("Time to eat: %d ms\n", philos[i].time_to_eat);
        printf("Time to sleep: %d ms\n", philos[i].time_to_sleep);
        printf("Nb of eating: %d\n", philos[i].nb_of_eating);
        printf("Time start: %ld\n", philos[i].time_start);
        printf("Last meal time: %ld\n", philos[i].last_meal_time);
        printf("\n\n");
        i++;
    }
}