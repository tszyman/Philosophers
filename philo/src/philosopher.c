/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:34:57 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 00:34:58 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_time = philo->data->start_time;

	if (philo->data->num_philos == 1){
		print_msg(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die);
		return(0);
	}
	philo->last_meal_time = philo->data->start_time;
	if (philo->id % 2 == 0) //even philos wait first
		ft_usleep(philo->data->time_to_eat / 2 + 10); 
	while(!is_sim_end(philo->data)){
		philo_eat(philo);
		if(is_sim_end(philo->data))
			break;
		philo_sleep(philo);
		if(is_sim_end(philo->data))
			break;
		philo_think(philo);
	}
	return(0);
}
void	philo_eat(t_philo *philo)
{
	if (is_sim_end(philo->data))
		return;
	if (take_forks(philo) != 0)
		return;

	
	print_msg_eat(philo, YELLOW"is eating"RESET);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	//printf(YELLOW"Philosopher: %d ate %d meals\n"RESET, philo->id, philo->meals_eaten);
	pthread_mutex_unlock(&philo->meal_mutex);
	drop_forks(philo);
}
void	philo_sleep(t_philo *philo)
{
	if (is_sim_end(philo->data))
		return;
	print_msg(philo, CYAN"is sleeping"RESET);
	ft_usleep(philo->data->time_to_sleep);
}
void	philo_think(t_philo *philo)
{
	if (is_sim_end(philo->data))
		return;
	print_msg(philo, BLUE"is thinking"RESET);
	usleep(100);
}