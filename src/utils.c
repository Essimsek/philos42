#include "../include/philo.h"

int	my_atoi(char *str)
{
	int			i;
	long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > INT_MAX)
		return (0);
	return (n);
}

void	printmessage(t_philo *philo, int state)
{
	if (state == STATE_SLEEPING)
		printf("%lld\t%d is sleeping.\n", get_time_in_ms()
			- philo->vars->init_time, philo->id);
	else if (state == STATE_THINKING)
		printf("%lld\t%d is thinking.\n", get_time_in_ms()
			- philo->vars->init_time, philo->id);
	else if (state == STATE_EATING)
		printf("%lld\t%d is eating.\n", get_time_in_ms() - philo->vars->init_time,
			philo->id);
	else if (state == STATE_DEAD)
		printf("%lld\t%d died\n", get_time_in_ms()
			- philo->vars->init_time, philo->id);
	else if (state == STATE_FORK)
		printf("%lld\t%d has taken a fork.\n", get_time_in_ms()
			- philo->vars->init_time, philo->id);
}

int	print_philo_state(t_philo *philo, int state)
{
	t_vars	*vars;

	vars = philo->vars;
	pthread_mutex_lock(&vars->writing_lock);
	if (state == STATE_EATING)
	{
		philo->times_ate++;
	}
	if (philo->times_ate == vars->inputs.min_times_eat && \
		state == STATE_EATING)
		vars->philos_ate_count++;
	if (vars->game_over == TRUE)
	{
		pthread_mutex_unlock(&vars->writing_lock);
		return (FALSE);
	}
	printmessage(philo, state);
	if (state == STATE_DEAD || vars->inputs.num_of_philo == vars->philos_ate_count)
		vars->game_over = TRUE;
	pthread_mutex_unlock(&vars->writing_lock);
	return (TRUE);
}