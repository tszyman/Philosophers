/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:34:38 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 00:56:45 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (parse_args(argc, argv, &data) != 0)
	{
		print_error("Invalid agruments.");
		return (1);
	}
	if (init_data(&data) != 0)
	{
		print_error("Failed to initialize data");
		cleanup_data(&data);
		return (1);
	}
	printf(GREEN"Initialization successful!\n"RESET);
	printf("Philosophers: %d\n", data.num_philos);
	printf("Time to die: %ld ms\n", data.time_to_die);
	printf("Time to eat: %ld ms\n", data.time_to_eat);
	printf("Time to sleep: %ld ms\n", data.time_to_sleep);
	if (data.must_eat_count != -1)
		printf("Must eat count: %d\n", data.must_eat_count);
	printf("Mutexes initialized: %d forks + print + death\n", data.num_philos);
	if (start_sim(&data) != 0)
	{
		print_error("Failed to start simulation!");
		cleanup_data(&data);
		return (1);
	}
	i = 0;
	while (i < data.num_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	pthread_join(data.monitor_thr, NULL);
	cleanup_data(&data);
	return (0);
}
/*TODO*/
/*Refactor: function has more than 25 lines*/