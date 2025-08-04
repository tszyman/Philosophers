/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:34:46 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 01:00:37 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_philo_death(t_philo *philo, long current_time)
{
	long	last_meal;
	int		is_dead;

	pthread_mutex_lock(&philo->meal_mutex);
	last_meal = current_time - philo->last_meal_time;
	is_dead = (last_meal > philo->data->time_to_die);
	if (is_dead)
	{
		print_msg(philo, RED"died!!!!"RESET);
		pthread_mutex_lock(&philo->data->death_mutex);
		philo->data->sim_end = 1;
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

int	check_philos_fed(t_data *data)
{
	int	i;
	int	all_fed;
	int	curr_meals;

	all_fed = 1;
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		curr_meals = data->philos[i].meals_eaten;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if (curr_meals < data->must_eat_count)
		{
			all_fed = 0;
			break ;
		}
		i++;
	}
	return (all_fed);
}

void	*death_monitor(void *arg)
{
	t_data	*data;
	int		i;
	long	curr_time;

	data = (t_data *)arg;
	while (!is_sim_end(data))
	{
		curr_time = get_current_time();
		i = 0;
		while (i < data->num_philos && !is_sim_end(data))
		{
			if (!data->philos)
				return (0);
			if (check_philo_death(&data->philos[i], curr_time))
				return (0);
			i++;
		}
		if (data->must_eat_count != -1 && check_philos_fed(data))
		{
			printf("All philos fed.\n");
			set_sim_end(data);
			return (0);
		}
		usleep (1000);
	}
	return (0);
}

void	set_sim_end(t_data *data)
{
	printf("Simulation has ended!\n");
	pthread_mutex_lock(&data->death_mutex);
	data->sim_end = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

/*TODO*/
/*Refactor: function has more than 25 lines*/