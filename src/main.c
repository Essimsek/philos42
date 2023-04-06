#include "../include/philo.h"

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
	if (create_philos(&vargs, 0) == FALSE)
		return (-1);
	return (0);
}
