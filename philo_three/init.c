/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:52:07 by skang             #+#    #+#             */
/*   Updated: 2021/03/09 16:52:13 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_three.h"

int		init_sems(t_sem *sems, t_pd *pd)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_unlink("state_main");
	sem_unlink("state_philo");
	if ((sems->s_forks = \
	sem_open("forks", O_CREAT, 0644, pd->num_of_philo / 2)) == SEM_FAILED)
		return (-1);
	if ((sems->s_write = \
	sem_open("write", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (-1);
	if ((sems->s_meal = \
	sem_open("meal", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (-1);
	if ((sems->s_state_main = \
	sem_open("state_main", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (-1);
	if ((sems->s_state_philo = \
	sem_open("state_philo", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (-1);
	return (0);
}

void	init_struct(t_philo *ph, t_pd *pd, t_sem *sems)
{
	if (!(ph->pid = (pid_t *)malloc(sizeof(pid_t) * pd->num_of_philo)))
		return ;
	ph->pd = pd;
	ph->sems = sems;
	ph->program_start = get_time();
	ph->last_meal = get_time();
}
