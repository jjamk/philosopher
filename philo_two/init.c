/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:39:11 by skang             #+#    #+#             */
/*   Updated: 2021/03/10 23:39:13 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_two.h"

int		init_sems(t_sem *sems, t_pd *pd)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	if ((sems->s_forks = \
	sem_open("forks", O_CREAT, 0644, pd->num_of_philo / 2)) == SEM_FAILED)
		return (-1);
	if ((sems->s_write = \
	sem_open("write", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (-1);
	if ((sems->s_meal = sem_open("meal", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (-1);
	return (0);
}

t_philo	*init_threads(t_pd *pd, t_sem *sems)
{
	t_philo *ph;
	int		i;

	i = 0;
	if (!(ph = (t_philo *)malloc(sizeof(t_philo) * pd->num_of_philo)))
		return (NULL);
	while (i < pd->num_of_philo)
	{
		ph[i].philo_idx = i + 1;
		ph[i].pd = pd;
		ph[i].sems = sems;
		ph[i].program_start = get_time();
		ph[i].last_meal = get_time();
		i++;
	}
	return (ph);
}
