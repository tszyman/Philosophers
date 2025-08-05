/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:34:31 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 22:25:47 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_data(t_data *data)
{
	data->sim_end = 0;
	data->start_time = 0;
	data->forks = NULL;
	data->philos = NULL;
	if (init_mutexes(data) != 0)
		return (1);
	if (init_philos(data) != 0)
	{
		destroy_mutexes(data);
		return (1);
	}
	assign_forks(data);
	return (0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (1);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (1);
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->philos[i].meal_mutex);
			free(data->philos);
			return (1);
		}
		i++;
	}
	return (0);
}

void	assign_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].right_fork = &data->forks[i];
		data->philos[i].left_fork = &data->forks[(i + 1) % data->num_philos];
		i++;
	}
}

int	init_and_validate_args(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		print_error("Invalid number of arguments.");
		return (1);
	}
	printf(GREEN"Program run successfully!\n"RESET);
	if (parse_args(argc, argv, data) != 0)
	{
		print_error("Invalid agruments.");
		return (1);
	}
	if (init_data(data) != 0)
	{
		print_error("Failed to initialize data");
		cleanup_data(data);
		return (1);
	}
	printf(GREEN"Initialization successful!\n"RESET);
	printf("Philosophers: %d\n", data->num_philos);
	printf("Time to die: %ld ms\nTime to eat: %ld ms\nTime to sleep: %ld ms\n",
		data->time_to_die, data->time_to_eat, data->time_to_sleep);
	if (data->must_eat_count != -1)
		printf("Must eat count: %d\n", data->must_eat_count);
	printf("Mutexes initialized: %d forks + print + death\n", data->num_philos);
	return (0);
}
