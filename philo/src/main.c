#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

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
	if (init_data(&data) != 0){
		print_error("Failed to initialize data");
		cleanup_data(&data);
		return(1);
	}
	printf(GREEN"Initialization successful!\n"RESET);
	//Print initialized values for verification
	printf("Philosophers: %d\n", data.num_philos);
	printf("Time to die: %ld ms\n", data.time_to_die);
	printf("Time to eat: %ld ms\n", data.time_to_eat);
	printf("Time to sleep: %ld ms\n", data.time_to_sleep);
	if (data.must_eat_count != -1)
		printf("Must eat count: %d\n", data.must_eat_count);
	printf("Mutexes initialized: %d forks + print + death\n", data.num_philos);
	if (start_sim(&data) != 0){
		print_error("Failed to start simulation!");
		cleanup_data(&data);
		return(1);
	}
	i = 0;
	while(i < data.num_philos){
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	
	cleanup_data(&data);
	return (0);
}
