/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:32:19 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 22:19:32 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define BLACK "\033[0;30m"
# define RESET "\033[0m"

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	struct s_data	*data;
}	t_philo;

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
	pthread_t		monitor_thr;
}	t_data;

//Function prototypes
/* parsing */
int		parse_args(int argc, char **argv, t_data *data);
int		ft_atoi(const char *str);
int		is_valid_number(const char *str);

/* init */
int		init_data(t_data *data);
int		init_mutexes(t_data *data);
int		init_philos(t_data *data);
void	assign_forks(t_data *data);
int		init_and_validate_args(int argc, char **argv, t_data *data);

/* clean-up */
void	cleanup_data(t_data *data);
void	destroy_mutexes(t_data *data);

/* Philos functions */
void	*philo_life(void *arg);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
int		take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);

/* simulation */
int		start_sim(t_data *data);
int		is_sim_end(t_data *data);
void	set_sim_end(t_data *data);

/* death monitoring */
int		check_philo_death(t_philo *philo, long current_time);
int		check_philos_fed(t_data *data);
void	*death_monitor(void *arg);

/* utils */
long	get_current_time(void);
void	ft_usleep(long time);
void	print_error(const char *msg);
void	print_msg(t_philo *philo, const char *msg);
void	print_msg_eat(t_philo *philo, const char *msg);

#endif