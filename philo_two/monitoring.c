/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:39:37 by skang             #+#    #+#             */
/*   Updated: 2021/03/10 23:39:44 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_two.h"

int		messages(const char *str, t_philo *ph)
{
	sem_wait(ph->sems->s_write);
	if (ph->pd->state != DIED && ph->pd->state != FULL)
	{
		ft_putnbr_fd(get_time() - ph->program_start, 1);
		ft_putstr("ms ");
		ft_putnbr_fd(ph->philo_idx, 1);
		ft_putstr(str);
	}
	sem_post(ph->sems->s_write);
	return (0);
}

void	*is_full(void *tmp_ph)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)tmp_ph;
	while (ph[0].pd->state != FULL && ph[0].pd->state != DIED)
	{
		i = 0;
		while (i < ph[0].pd->num_of_philo && ph[0].pd->state != FULL &&
		ph[0].pd->state != DIED)
		{
			if (ph[i].pd->num_of_meals ==
			(ph[0].pd->num_of_philo * ph[0].pd->num_of_must_eat))
			{
				ph[i].pd->state = FULL;
			}
			i++;
		}
	}
	return (NULL);
}

void	*is_die(void *tmp_ph)
{
	t_philo			*ph;

	ph = (t_philo *)tmp_ph;
	while (42 && ph->pd->state != DIED && ph->pd->state != FULL)
	{
		if (get_time() - ph->last_meal > ph->pd->time_to_die)
		{
			messages(" is died\n", ph);
			ph->pd->state = DIED;
		}
	}
	return (NULL);
}

void	eating(t_philo *ph)
{
	sem_wait(ph->sems->s_forks);
	messages(" has take a fork\n", ph);
	messages(" is eating\n", ph);
	ph->last_meal = get_time();
	usleep(ph->pd->time_to_eat);
	sem_wait(ph->sems->s_meal);
	ph->pd->num_of_meals++;
	sem_post(ph->sems->s_meal);
	sem_post(ph->sems->s_forks);
}
