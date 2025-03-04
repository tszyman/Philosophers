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
	if (init_data(&data, argv) != 0)
	{
		return (1); //Exit if initialization failed
	}
	//Print initialized values for verification
	printf("Philosophers: %d\n", data.num_philos);
	printf("Time to die: %d\n", data.time_to_die);
	printf("Time to eat: %d\n", data.time_to_eat);
	printf("Time to sleep: %d\n", data.time_to_sleep);

	//Continue

	return (0);
}
