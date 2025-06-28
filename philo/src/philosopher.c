#include "../includes/philo.h"

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_time = philo->data->start_time;
	if (philo->id % 2 == 0) //even philos wait first
		ft_usleep(philo->data->time_to_eat / 2); // div by 2 is arbitrary
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
	philo->last_meal_time = get_current_time();
	print_msg(philo, YELLOW"is eating"RESET);
	ft_usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	drop_forks(philo);
}
void	philo_sleep(t_philo *philo)
{
	if (is_sim_end(philo->data))
		return;
	print_msg(philo, GREY"is sleeping"RESET);
	ft_usleep(philo->data->time_to_sleep);
}
void	philo_think(t_philo *philo)
{
	if (is_sim_end(philo->data))
		return;
	print_msg(philo, BLUE"is thinking"RESET);
}