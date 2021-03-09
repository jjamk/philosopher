/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:50:00 by skang             #+#    #+#             */
/*   Updated: 2021/03/09 16:50:02 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/philo_one.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}

void	exit_thread(t_philo *philo, t_mutex *mutex, t_data *data)
{
	int			i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&(mutex->forks)[i]);
		i++;
	}
	pthread_mutex_destroy(&(mutex->write));
	pthread_mutex_destroy(&(mutex->state));
	pthread_mutex_destroy(&(mutex->count));
	free(philo);
	free(mutex->forks);
}

int		make_thread(t_philo *philo, t_data *data)
{
	pthread_t	full;
	int			i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, is_print, &philo[i]) < 0)
		{
			write(1, "Error thread\n", 13);
			return (-1);
		}
		usleep(18);
		i++;
	}
	pthread_create(&full, NULL, &is_full, (void *)philo);
	pthread_detach(full);
	i = 0;
	while (i < data->num_of_philo)
		pthread_join(philo[i++].thread, NULL);
	return (0);
}

int		main(int argc, const char **argv)
{
	t_philo	*philo;
	t_mutex	mutex;
	t_data	data;

	if (argc < 5)
		write(1, "Error argc\n", 11);
	else
	{
		if (input_arg(&data, argv) == -1)
			return (0);
		if (init_mutex(&mutex, &data) == -1)
			return (0);
		philo = init_thread(&data, &mutex);
		make_thread(philo, &data);
		exit_thread(philo, &mutex, &data);
	}
	return (0);
}
