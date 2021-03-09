#ifndef		PHILO_ONE_H
# define	PHILO_ONE_H
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include	<sys/wait.h>
# include	<sys/time.h>
# include	<pthread.h>
# include	<stdlib.h>
# include	"utils.h"

typedef struct	s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	state;
	pthread_mutex_t	count;
}				t_mutex;

typedef struct	s_data
{
	int				num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			count;
	int				must_count;
	int				state;
}				t_data;

typedef struct	s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_mutex			*mutex;
	t_data			*data;
	int				philo_index;
	long			last_eat;
	long			start;
}				t_philo;

t_philo	*init_thread(t_data *data, t_mutex *mutex);
int init_mutex(t_mutex *mutex, t_data *data);

int	input_arg(t_data *data, const char **argv);
void	*is_print(void *philo_tmp);
void	is_eating(t_philo *philo);
void	*is_die(void *philo_tmp);
int		print(char *str, t_philo *philo);
void	*is_full(void *philo_tmp);

int		make_thread(t_philo *philo, t_data *data);
void	exit_thread(t_philo *philo, t_mutex *mutex, t_data *data);
long	get_time(void);

#endif