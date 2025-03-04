#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	printf("Program run successfully\n");
	//Call init_data and check for success
	if (init_data(&data, argc, argv) != 0)
	{
		return (1); //Exit if initialization failed
	}
	//Print initialized values for verification
	printf("Philosophers: %d\n", data.num_philos);
	printf("Time to die: %d\n", data.time_to_die);
	printf("Time to eat: %d\n", data.time_to_eat);
	printf("Time to sleep: %d\n", data.time_to_sleep);
	printf("Number of meals: %d\n", data.num_meals);
	printf("Is dead: %d\n", data.dead);
	//printf("Start time: %lld\n", data.start_time);

	//Continue

	return (0);
}
