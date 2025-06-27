#include "../includes/philo.h"

void	cleanup_data(t_data *data)
{
	destroy_mutexes(data);
	if (data->philos){
		free(data->philos);
		data->philos = NULL;
	}
	if (data->forks){
		free(data->forks);
		data->forks = NULL;
	}
}
void	destroy_mutexes(t_data *data)
{
	int	i;

	if (data->forks){
		i = 0;
		while(i < data->num_philos){
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}
