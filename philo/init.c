#include "philo.h"

int	init_data(t_data *data, char **argv)
{
	// Parse arguments and initialize data
	data->num_philos = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);

	//validate values

	if (data->num_philos <= 0 || data->time_to_die <= 0 ||
		data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		{
			printf("Error: Invalid arguments\n");
			return (1);
		}
	return (0);
}
