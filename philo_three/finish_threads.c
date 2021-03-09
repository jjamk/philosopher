/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:52:24 by skang             #+#    #+#             */
/*   Updated: 2021/03/09 16:52:26 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_three.h"

void	finish_semaphores(t_philo *ph)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_unlink("state_main");
	sem_unlink("state_philo");
	sem_close(ph->sems->s_forks);
	sem_close(ph->sems->s_write);
	sem_close(ph->sems->s_meal);
	sem_close(ph->sems->s_state_main);
	sem_close(ph->sems->s_state_philo);
}

void	wait_and_exit(t_philo *ph)
{
	int	i;

	i = 0;
	waitpid(-1, NULL, 0);
	while (i < ph->pd->num_of_philo)
	{
		kill(ph->pid[i], SIGTERM);
		i++;
	}
	free(ph->pid);
}
