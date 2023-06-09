/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:14:26 by esimsek           #+#    #+#             */
/*   Updated: 2023/04/12 23:14:27 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	wait_ms(int ms)
{
	long long	start_time;

	start_time = get_time_in_ms();
	while (get_time_in_ms() - start_time < ms)
		usleep(30);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;

	if (check_args(&vars.inputs, av, ac) == FALSE)
		return (-1);
	if (init_mutex(&vars) == FALSE)
		return (-1);
	if (init_philos(&vars) == FALSE)
		return (-1);
	if (create_threads(&vars, 1) == FALSE)
		return (-1);
	i = -1;
	dead_check(&vars);
	while (++i < vars.inputs.num_of_philo)
		pthread_join(vars.philos[i].philo, NULL);
	free_all(&vars);
	return (0);
}
