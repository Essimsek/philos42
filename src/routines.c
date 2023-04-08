#include "../include/philo.h"

int	eating(t_philo *philo)
{
	t_vars	*vars;
	int		is_true;

	vars = philo->vars;
	pthread_mutex_lock(&vars->forks[philo->fork.left]);
	pthread_mutex_lock(&vars->forks[philo->fork.right]);
	is_true = print_philo_state(philo, STATE_FORK);
	is_true = print_philo_state(philo, STATE_FORK);
	is_true = print_philo_state(philo, STATE_EATING);
	pthread_mutex_lock(&philo->mutex);
	philo->last_eat_time = get_time_in_ms();
	pthread_mutex_unlock(&philo->mutex);
	usleep(vars->inputs.time_to_eat * 1000);
	pthread_mutex_unlock(&vars->forks[philo->fork.left]);
	pthread_mutex_unlock(&vars->forks[philo->fork.right]);
	return (is_true);
}

int	philo_eating(t_philo *philo)
{
	if (philo->id == 1)
		philo->fork.left = philo->vars->inputs.num_of_philo - 1;
	else
		philo->fork.left = philo->id - 2;
	philo->fork.right = philo->id - 1;
	return (eating(philo));
}

int	philo_sleeping(t_philo *philo)
{
	int	is_true;

	is_true = print_philo_state(philo, STATE_SLEEPING);
	usleep(philo->vars->inputs.time_to_sleep * 1000);
	return (is_true);
}	

int philo_thinking(t_philo *philo)
{
	int	is_true;

	is_true = print_philo_state(philo, STATE_THINKING);
	return (is_true);
}