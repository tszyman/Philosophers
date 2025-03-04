#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"


typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	long long 		last_meal_time;
	struct s_data 	*data;
	pthread_t 		thread;
} t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				dead;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
} t_data;

//Function prototypes

int	init_data(t_data *data, int argc, char **argv);

#endif
