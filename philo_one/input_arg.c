/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:49:56 by skang             #+#    #+#             */
/*   Updated: 2021/03/09 21:18:39 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_one.h"

static int	check_philo_num(int num_of_philo)
{
	if (num_of_philo <= 1)
	{
		write(1, "Errorcheck\n", 11);
		return (1);
	}
	return (0);
}

static int	check_arg(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_number(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			input_arg(t_data *data, const char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_arg(argv[i]))
		{
			write(1, "Errorinput\n", 11);
			return (-1);
		}
		i++;
	}
	data->count = 0;
	data->state = 0;
	data->num_of_philo = (int)ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		data->must_count = (int)ft_atoi(argv[5]);
	else
		data->must_count = -1;
	if (check_philo_num(data->num_of_philo))
		return (-1);
	return (0);
}
