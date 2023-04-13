/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:17:20 by esimsek           #+#    #+#             */
/*   Updated: 2023/04/12 23:17:21 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_vars *vars)
{
	int	i;

	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->inputs.num_of_philo);
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

int	init_philos(t_vars *vars)
{
	vars->philos_ate_count = 0;
	vars->game_over = FALSE;
	vars->init_time = get_time_in_ms();
	vars->philos = malloc(sizeof(t_philo) * vars->inputs.num_of_philo + 1);
	if (vars->philos == NULL)
		return (FALSE);
	return (TRUE);
}
