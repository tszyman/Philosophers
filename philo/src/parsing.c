#include "../includes/philo.h"

int		ft_atoi(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9'){
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
int		is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return(0);
	while (str[i]){
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1); // 1 is returned to make usage easier. If we check: if (is_valid_number('7')), we expect 1 if it's valid, 0 otherwise
}
int		parse_args(int argc, char **argv, t_data *data)
{
	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]) ||
		!is_valid_number(argv[3]) || !is_valid_number(argv[4]))
		return (1);
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6){
		if (!is_valid_number(argv[5]))
			return (1);
		data->must_eat_count = ft_atoi(argv[5]);
	}
	else
		data->must_eat_count = -1;
	if (data->num_philos <= 0 || data->time_to_die <= 0 ||
		data->time_to_eat <=0 || data->time_to_sleep <= 0)
		return (1);
	return (0);
}
