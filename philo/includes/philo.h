#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"


typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t 		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data 	*data;
} t_philo;

typedef struct s_data
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;
	long			start_time;
	int				sim_end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
} t_data;

//Function prototypes
/* parsing */
int		parse_args(int argc, char **argv, t_data *data);
int		ft_atoi(const char *str);
int		is_valid_number(const char *str);

/* utils */
long	get_current_time(void);
void	ft_usleep(long time);
void	print_error(const char *msg);

#endif
