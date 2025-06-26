#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		print_error("Invalid number of arguments.");
		return (1);
	}
	printf(GREEN"Program run successfully!\n"RESET);
	//Call init_data and check for success
	if (parse_args(argc, argv, &data) != 0)
	{
		print_error("Invalid agruments.");
		return (1); //Exit if initialization failed
	}
	//Print initialized values for verification
	printf("Philosophers: %d\n", data.num_philos);
	printf("Time to die: %ld ms\n", data.time_to_die);
	printf("Time to eat: %ld ms\n", data.time_to_eat);
	printf("Time to sleep: %ld ms\n", data.time_to_sleep);
	if (data.must_eat_count != -1)
		printf("Must eat count: %d\n", data.must_eat_count);
	return (0);
}
