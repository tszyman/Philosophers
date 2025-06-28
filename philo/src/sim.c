#include "../includes/philo.h"

int		start_sim(t_data *data)
{
	int	i;

	data->start_time = get_current_time();
	i = 0;
	while(i < data->num_philos){
		if (pthread_create(&data->philos[i].thread, NULL, philo_life, &data->philos[i]) != 0){
			print_error("Failed to create a thread");
			return(1);
		}
		i++;
	}
	return(0);
}
int		is_sim_end(t_data *data)
{
	int	end;
	pthread_mutex_lock(&data->death_mutex);
	end = data->sim_end;
	pthread_mutex_unlock(&data->death_mutex);
	return (end);
}