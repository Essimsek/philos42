#include "../include/philo.h"

static void	*loop(void *philo)
{
	t_philo	arg = *(t_philo *)philo;
	printf("%lld: ", arg.last_eat_time);
	printf("Thread with id: %d created!\n", arg.id);
	return (NULL);
}

static void	assignment_for_philosss(t_vars *vars, int i)
{
			vars->philos[i].id = i + 1;
			vars->philos[i].last_eat_time = get_time_in_ms();
			vars->philos[i].fork.left = 0;
			vars->philos[i].fork.right = 0;
			vars->philos[i].times_ate = 0;
			vars->philos[i].time_to_die = 0;
			vars->philos[i].state = STATE_THINKING;
}

int	create_philos(t_vars *vars, int odd_even)
{
	int	i;

	vars->philos = malloc(sizeof(t_philo) * vars->inputs.num_of_philo + 1);
	if (vars->philos == NULL)
		return (FALSE);
	i = -1;
	while (++i < vars->inputs.num_of_philo)
	{
		if (i % 2 == odd_even)
		{
			assignment_for_philosss(vars, i);
			vars->philos[i].philo = malloc(sizeof(pthread_t));
			if (pthread_create(&vars->philos[i].philo, NULL, &loop, &vars->philos[i]) != 0)
				return (FALSE);
		}
		usleep(1000);
	}
	if (odd_even == 0)
		create_philos(vars, 1);
	vars->game_over = FALSE;
	return (TRUE);
}
