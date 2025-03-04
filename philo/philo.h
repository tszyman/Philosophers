#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	int	id;
	int	left_fork;
	int	right_fork;
	long long last_meal;
	struct s_data *data;
	pthread_t thread;
} t_philo;
typedef struct s_data
{
	int num_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	long long start_time;
	int stop;
	pthread_mutex_t *forks;
	pthread_mutex_t write_lock;
	pthread_mutex_t meal_lock;
	t_philo *philos;
} t_data;

//Function prototypes

int	init_data(t_data *data, char **argv);

#endif
