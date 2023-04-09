#include "../include/philo.h"

void	destroy_mutexes(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->inputs.num_of_philo)
	{
		pthread_mutex_destroy(&vars->forks[i]);
		pthread_mutex_destroy(&vars->philos[i].mutex);
	}
	pthread_mutex_destroy(&vars->writing_lock);
}

void free_philos(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->inputs.num_of_philo)
		free(&vars->philos[i]);
}

void	free_all(t_vars *vars)
{
	destroy_mutexes(vars);
	free_philos(vars);
}