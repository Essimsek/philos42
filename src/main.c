#include "../include/philo.h"

int	create_philos(t_vargs *vargs)
{
	int	i;

	i = 0;
	vargs->philos = malloc(sizeof(t_philo) * vargs->inputs.num_of_philo + 1);
	if (vargs->philos == NULL)
		return (FALSE);
	while (i < vargs->inputs.num_of_philo)
	{
		vargs->philos[i].id = i + 1;
		vargs->philos[i].fork.left = 0;
		vargs->philos[i].fork.right = 0;
		vargs->philos[i].times_ate = 0;
		vargs->philos[i].time_to_die = 0;
		vargs->philos[i].state = STATE_THINKING;
		vargs->philos[i].philo = malloc(sizeof(pthread_t));
		i++;
	}
	vargs->game_over = FALSE;
	return (TRUE);
}

long long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main(int ac, char **av)
{
	t_vargs	vargs;

	if (check_args(&vargs.inputs, av, ac) == FALSE)
		return (-1);
	if (create_philos(&vargs) == FALSE)
		return (-1);
	
	return (0);
}
