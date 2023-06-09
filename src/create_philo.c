/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:16:19 by esimsek           #+#    #+#             */
/*   Updated: 2023/04/12 23:16:20 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_loop(void *philoshopher)
{
	t_philo		*philo;
	int			is_loop_on;

	philo = (t_philo *)philoshopher;
	is_loop_on = TRUE;
	while (is_loop_on)
	{
		if (philo_eating(philo) == FALSE)
			is_loop_on = FALSE;
		if (philo_sleeping(philo) == FALSE)
			is_loop_on = FALSE;
		if (philo_thinking(philo) == FALSE)
			is_loop_on = FALSE;
	}
	return (NULL);
}

static void	assignment_for_philosss(t_vars *vars, int i)
{
			vars->philos[i].id = i + 1;
			vars->philos[i].last_eat_time = get_time_in_ms();
			vars->philos[i].fork.left = 0;
			vars->philos[i].fork.right = 0;
			vars->philos[i].times_ate = 0;
			vars->philos[i].vars = vars;
}

int	create_threads(t_vars *vars, int odd_even)
{
	int	i;

	i = -1;
	while (++i < vars->inputs.num_of_philo)
	{
		if (i % 2 == odd_even)
		{
			assignment_for_philosss(vars, i);
			if (pthread_mutex_init(&vars->philos[i].mutex, NULL) != 0)
				return (FALSE);
			if (pthread_create(&vars->philos[i].philo, NULL, philo_loop, \
					&vars->philos[i]) != 0)
				return (FALSE);
		}
		usleep(1000);
	}
	if (odd_even == 1)
		create_threads(vars, 0);
	return (TRUE);
}
