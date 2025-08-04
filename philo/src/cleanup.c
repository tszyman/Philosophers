/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:34:15 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 00:36:31 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cleanup_data(t_data *data)
{
	destroy_mutexes(data);
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	if (data->philos)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->philos[i].meal_mutex);
			i++;
		}
	}
	if (data->forks)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}
