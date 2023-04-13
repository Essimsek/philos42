/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:16:40 by esimsek           #+#    #+#             */
/*   Updated: 2023/04/12 23:16:41 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	dead_check(t_vars *vars)
{
	int	i;
	int	is_true;

	is_true = TRUE;
	while (1)
	{
		usleep(100);
		i = -1;
		while (++i < vars->inputs.num_of_philo)
		{
			pthread_mutex_lock(&vars->philos[i].mutex);
			if (get_time_in_ms() - vars->philos[i].last_eat_time \
								>= vars->inputs.time_to_die)
				is_true = print_philo_state(&vars->philos[i], STATE_DEAD);
			pthread_mutex_unlock(&vars->philos[i].mutex);
			if (is_true == FALSE)
				return ;
			usleep(vars->inputs.num_of_philo);
		}
	}
	return ;
}
