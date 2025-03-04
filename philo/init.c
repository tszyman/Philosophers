#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	// Parse arguments and initialize data
	data->num_philos = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->num_meals = atoi(argv[5]);
	else
		data->num_meals = -1;
	data->dead = 0;
	//data->start_time = gettime();

	//validate values

	if (data->num_philos <= 0 || data->time_to_die <= 0 ||
		data->time_to_eat <= 0 || data->time_to_sleep <= 0 ||
		(argc == 6 && data->num_meals <= 0))
		{
			printf("Error: Invalid arguments\n");
			return (1);
		}
	return (0);
}
