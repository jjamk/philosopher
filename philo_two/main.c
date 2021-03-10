/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:39:19 by skang             #+#    #+#             */
/*   Updated: 2021/03/11 00:25:17 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_two.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}

void	*print_do(void *tmp_ph)
{
	t_philo		*ph;
	pthread_t	died;

	ph = (t_philo *)tmp_ph;
	pthread_create(&died, NULL, &is_die, (void *)ph);
	pthread_detach(died);
	while (ph->pd->state != DIED && ph->pd->state != FULL)
	{
		eating(ph);
		messages(" is sleeping\n", ph);
		usleep(ph->pd->time_to_sleep);
		messages(" is thinking\n", ph);
	}
	return (NULL);
}

void	finish_semaphores(t_philo *ph, t_sem *sems)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_close(sems->s_meal);
	sem_close(sems->s_forks);
	sem_close(sems->s_write);
	free(ph);
}

int		make_threads(t_philo *ph, t_pd *pd)
{
	pthread_t	full;
	int			i;

	i = 0;
	while (i < pd->num_of_philo)
	{
		if (pthread_create(&ph[i].thread, NULL, print_do, &ph[i]) < 0)
		{
			ft_putstr("thread create error\n");
			return (-1);
		}
		usleep(20);
		i++;
	}
	pthread_create(&full, NULL, &is_full, (void *)ph);
	pthread_detach(full);
	i = 0;
	while (i < pd->num_of_philo)
		pthread_join(ph[i++].thread, NULL);
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo		*ph;
	t_sem		sems;
	t_pd		pd;

	if (argc < 5)
		ft_putstr("Error\n");
	else
	{
		if (input_args(&pd, (const char **)argv) == -1)
			return (0);
		if (init_sems(&sems, &pd) == -1)
			return (0);
		ph = init_threads(&pd, &sems);
		make_threads(ph, &pd);
		finish_semaphores(ph, &sems);
	}
	return (0);
}
