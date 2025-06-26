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