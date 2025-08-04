/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:35:06 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 00:35:07 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // total time: tv_sec + tv_usec from 1.01.1970, we need to convert sec -> mili + micro -> mili
}

void	ft_usleep(long time)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < time)
		usleep(100);
}

void	print_error(const char *msg)
{
	printf(RED"Error: %s\n"RESET, msg);
}

void	print_msg(t_philo *philo, const char *msg)
{
	long	timestamp;

	if (!philo || !philo->data || !msg)
		return;
	if (is_sim_end(philo->data))
		return;
	if (pthread_mutex_lock(&philo->data->print_mutex) != 0)
		return;
	if (is_sim_end(philo->data)){
		pthread_mutex_unlock(&philo->data->print_mutex);
		return;
	}
	timestamp = get_current_time() - philo->data->start_time;
	printf("[%ld] Philosopher: %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_msg_eat(t_philo *philo, const char *msg)
{
	long	timestamp;

	if (!philo || !philo->data || !msg)
		return;
	if (is_sim_end(philo->data))
		return;
	if (pthread_mutex_lock(&philo->data->print_mutex) != 0)
		return;
	if (is_sim_end(philo->data)){
		pthread_mutex_unlock(&philo->data->print_mutex);
		return;
	}
	timestamp = get_current_time() - philo->data->start_time;
	printf("[%ld] Philosopher: %d %s (meal #%d)\n", timestamp, philo->id, msg, philo->meals_eaten+1);
	pthread_mutex_unlock(&philo->data->print_mutex);
}