#include "includes/philo_one.h"

int		print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->write);
	if (philo->data->state != -1 && philo->data->state != 1)
	{
		ft_putnbr_fd(get_time() - philo->start, 1);
		write(1, "ms ", 3);
		ft_putnbr_fd(philo->philo_index, 1);
		ft_putstr(str);
	}
	pthread_mutex_unlock(&philo->mutex->write);
	return (0);
}

void	*is_full(void *tmp_ph)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)tmp_ph;
	while (philo[0].data->state != 1 && philo[0].data->state != -1)
	{
		i = 0;
		while (i < philo[0].data->num_of_philo && philo[0].data->state != 1 &&
		philo[0].data->state != -1)
		{
			if (philo[i].data->count ==
			(philo[0].data->num_of_philo * philo[0].data->must_count))
			{
				pthread_mutex_lock(&philo->mutex->state);
				philo[i].data->state = 1;
				pthread_mutex_unlock(&philo->mutex->state);
			}
			i++;
		}
	}
	return (NULL);
}

void	*is_die(void *philo_tmp)
{
	t_philo	*philo;

	philo = (t_philo*)philo_tmp;
	while (philo->data->state != -1 && philo->data->state != 1)
	{
		if (get_time() - philo->last_eat > philo->data->time_to_die)
		{
			print(" is died\n", philo);
			pthread_mutex_lock(&philo->mutex->state);
			philo->data->state = -1;
			pthread_mutex_unlock(&philo->mutex->state);
			break;
		}
	}
	return (NULL);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	print(" is has taken fork\n", philo);
	philo->last_eat = get_time();
	print(" is eating\n", philo);
	usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->mutex->count);
	philo->data->count++;
	pthread_mutex_unlock(&philo->mutex->count);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*is_print(void *philo_tmp)
{
	t_philo		*philo;
	pthread_t	die;

	philo = (t_philo*)philo_tmp;
	pthread_create(&die, NULL, &is_die, (void*)philo);
	pthread_detach(die);
	philo->philo_index % 2 == 1  ? 0 : usleep(philo->data->time_to_eat);
	while (philo->data->state != -1 && philo->data->state != 1)
	{
		is_eating(philo);
		print(" is sleeping\n", philo);
		usleep(philo->data->time_to_sleep);
		print(" is thinking\n", philo);
	}
	return (NULL);
}