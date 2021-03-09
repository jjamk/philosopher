
#include "includes/philo_three.h"

void	*convert_state_in_parent(void *tmp_ph)
{
	t_philo *ph;

	ph = (t_philo *)tmp_ph;
	sem_wait(ph->sems->s_state_main);
	ph->pd->state = -1;
	return (NULL);
}

void	*convert_state_in_child(void *tmp_ph)
{
	t_philo *ph;

	ph = (t_philo *)tmp_ph;
	sem_wait(ph->sems->s_state_philo);
	ph->pd->state = -1;
	sem_post(ph->sems->s_state_philo);
	return (NULL);
}

void	*is_full(void *tmp_ph)
{
	t_philo	*ph;
	int		cnt;

	ph = (t_philo *)tmp_ph;
	cnt = 0;
	while (42 && ph->pd->state != -1 && ph->pd->state != 1)
	{
		sem_wait(ph->sems->s_meal);
		cnt++;
		if (cnt == (ph->pd->num_of_philo * ph->pd->num_of_must_eat))
		{
			ph->pd->state = 1;
			sem_post(ph->sems->s_state_main);
			sem_post(ph->sems->s_state_philo);
			usleep(18 + 50);
			break ;
		}
	}
	return (NULL);
}

void	*is_die(void *tmp_ph)
{
	t_philo	*ph;

	ph = (t_philo *)tmp_ph;
	while (ph->pd->state != -1 && ph->pd->state != 1)
	{
		if (get_time() - ph->last_meal > ph->pd->time_to_die)
		{
			messages(" is died\n", ph);
			ph->pd->state = -1;
			sem_post(ph->sems->s_state_main);
			sem_post(ph->sems->s_state_philo);
			sem_post(ph->sems->s_meal);
			break ;
		}
	}
	return (NULL);
}
