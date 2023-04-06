#include "../include/philo.h"

static void	*loop()
{
	printf("Thread was created!\n");
	return (NULL);
}

static void	assignment_for_philosss(t_vargs *vargs, int	i)
{
			vargs->philos[i].id = i + 1;
			vargs->philos[i].fork.left = 0;
			vargs->philos[i].fork.right = 0;
			vargs->philos[i].times_ate = 0;
			vargs->philos[i].time_to_die = 0;
			vargs->philos[i].state = STATE_THINKING;
}

int	create_philos(t_vargs *vargs, int odd_even)
{
	int	i;

	vargs->philos = malloc(sizeof(t_philo) * vargs->inputs.num_of_philo + 1);
	if (vargs->philos == NULL)
		return (FALSE);
	i = -1;
	while (++i < vargs->inputs.num_of_philo)
	{
		if (i % 2 == odd_even)
		{
			assignment_for_philosss(vargs, i);
			vargs->philos[i].philo = malloc(sizeof(pthread_t));
			if (pthread_create(&vargs->philos[i].philo, NULL, &loop, NULL) != 0)
				return (FALSE);
		}
		usleep(1000);
	}
	if (odd_even == 0)
		create_philos(vargs, 1);
	vargs->game_over = FALSE;
	return (TRUE);
}
