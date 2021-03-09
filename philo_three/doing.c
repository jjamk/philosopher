
#include "includes/philo_three.h"

void	eating(t_philo *ph)
{
	sem_wait(ph->sems->s_forks);
	messages(" has taken a fork\n", ph);
	messages(" is eating\n", ph);
	ph->last_meal = get_time();
	usleep(ph->pd->time_to_eat);
	ph->pd->num_of_meals++;
	sem_post(ph->sems->s_meal);
	sem_post(ph->sems->s_forks);
}
