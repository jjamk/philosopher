
#include "includes/philo_two.h"

static int	check_args_validity(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_num_of_philo(int num_of_philo)
{
	if (num_of_philo == 1 || num_of_philo == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int			input_args(t_pd *pd, const char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!check_args_validity(argv[i]))
		{
			ft_putstr("Error\n");
			return (-1);
		}
		i++;
	}
	pd->num_of_meals = 0;
	pd->state = ALIVE;
	pd->num_of_philo = ft_atoi(argv[1]);
	pd->time_to_die = ft_atoi(argv[2]);
	pd->time_to_eat = ft_atoi(argv[3]) * 1000;
	pd->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		pd->num_of_must_eat = ft_atoi(argv[5]);
	else
		pd->num_of_must_eat = -1;
	if (check_num_of_philo(pd->num_of_philo))
		return (-1);
	return (0);
}