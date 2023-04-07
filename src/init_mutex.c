#include "../include/philo.h"

int	init_mutex(t_vars *vars)
{
	int	i;

	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->inputs.num_of_philo + 1);
	if (vars->forks == NULL)
		return (my_errors("malloc failed!\n"));
	i = 0;
	while (i < vars->inputs.num_of_philo)
	{
		if (pthread_mutex_init(&vars->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&vars->writing_lock, NULL) != 0)
		return (FALSE);
	return (TRUE);
}
