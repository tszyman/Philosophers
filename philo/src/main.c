/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:34:38 by tomek             #+#    #+#             */
/*   Updated: 2025/08/05 22:17:55 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (init_and_validate_args(argc, argv, &data) != 0)
		return (1);
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
