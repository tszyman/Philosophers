/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:35:02 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 00:35:03 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		start_sim(t_data *data)
{
	int	i;
	pthread_t monitor_t;

	data->start_time = get_current_time();
	i = 0;
	while(i < data->num_philos){
		if (pthread_create(&data->philos[i].thread, NULL, philo_life, &data->philos[i]) != 0){
			print_error("Failed to create a philo thread");
			return(1);
		}
		i++;
	}
	if (pthread_create(&monitor_t, NULL, death_monitor, data) != 0){
		print_error("Failed to create monitor thread.");
		return(1);
	}
	// podwojne joinowanie (w main.c już jest)
	// i = 0;
	// while (i < data->num_philos){
	// 	pthread_join(data->philos[i].thread, NULL);
	// 	i++;
	// }
	// pthread_join(monitor_t, NULL);
	data->monitor_thr = monitor_t;
	return(0);
}
int		is_sim_end(t_data *data)
{
	int	end;
	pthread_mutex_lock(&data->death_mutex);
	end = data->sim_end;
	pthread_mutex_unlock(&data->death_mutex);
	return (end);
}