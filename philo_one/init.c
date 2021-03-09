/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:49:38 by skang             #+#    #+#             */
/*   Updated: 2021/03/09 16:49:41 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_one.h"

int init_mutex(t_mutex *mutex, t_data *data)
{
	int i;

	i = 0;
	if (!(mutex->forks = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo)))
		return(-1);
	while(i < data->num_of_philo)
	{
		pthread_mutex_init(&mutex->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&mutex->write, NULL);
	pthread_mutex_init(&mutex->state, NULL);
	pthread_mutex_init(&mutex->count, NULL);
	return (0);
}

t_philo	*init_thread(t_data *data, t_mutex *mutex)
{
	t_philo	*philo;
	int		i;

	i = 0;
	if (!(philo = (t_philo*)malloc(sizeof(t_philo) * data->num_of_philo)))
		return (0);
	while (i < data->num_of_philo)
	{
		philo[i].philo_index = i + 1;
		philo[i].data = data;
		philo[i].mutex = mutex;
		philo[i].left_fork = &mutex->forks[i];
		if (i < 1)
			philo[i].right_fork = &mutex->forks[data->num_of_philo - 1];
		else
			philo[i].right_fork = &mutex->forks[i - 1];
		philo[i].start = get_time();
		philo[i].last_eat = get_time();
		i++;
	}
	return (philo);
}
