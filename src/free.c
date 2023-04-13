/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:17:14 by esimsek           #+#    #+#             */
/*   Updated: 2023/04/12 23:17:15 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	destroy_mutexes(t_vars *vars)
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

void	free_all(t_vars *vars)
{
	destroy_mutexes(vars);
}
