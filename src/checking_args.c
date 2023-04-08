#include "../include/philo.h"

static int	check_inputs(t_input *inputs, int num_of_args)
{
	if (!inputs->num_of_philo || !inputs->time_to_die \
					|| !inputs->time_to_eat || !inputs->time_to_sleep)
		return (FALSE);
	if (num_of_args == 6 && !inputs->min_times_eat)
		return (FALSE);
	return (TRUE);
}

static int	init_inputs(t_input *inputs, char **av, int num_of_args)
{
	if (num_of_args == 5 || num_of_args == 6)
	{
		inputs->num_of_philo = my_atoi(av[1]);
		inputs->time_to_die = my_atoi(av[2]);
		inputs->time_to_eat = my_atoi(av[3]);
		inputs->time_to_sleep = my_atoi(av[4]);
		if (num_of_args == 6)
			inputs->min_times_eat = my_atoi(av[5]);
		else
			inputs->min_times_eat = -1;
		return (TRUE);
	}
	return (FALSE);
}

int	check_args(t_input *inputs, char **av, int ac)
{
	if (init_inputs(inputs, av, ac) == FALSE)
		return (my_errors("The number of argments must be 4 or 5"));
	if (check_inputs(inputs, ac) == FALSE)
		return (my_errors("Check your arguments"));
	return (TRUE);
}
