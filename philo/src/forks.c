#include "../includes/philo.h"

static int	take_first_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (is_sim_end(philo->data)){
		pthread_mutex_unlock(fork);
		return(1);
	}
	//print_msg(philo, "has taken first fork");
	return(0);
}
static int	take_second_fork(t_philo *philo, pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(second_fork);
	if (is_sim_end(philo->data)){
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return(1);
	}
	//print_msg(philo, "has taken second fork");
	return(0);
}


int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	// int				first_id;
	// int				second_id;

	// first_id = philo->id - 1;
	// second_id = philo->id % philo->data->num_philos;
	// if (first_id < second_id){
	if (philo->id == 1){
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	else{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	if (take_first_fork(philo, first_fork) != 0)
		return(1);
	if (take_second_fork(philo, first_fork, second_fork) != 0)
		return(1);
	return(0);
}
void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}