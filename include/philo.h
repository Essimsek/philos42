/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:14:12 by esimsek           #+#    #+#             */
/*   Updated: 2023/04/12 23:15:55 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<sys/time.h>
# include<pthread.h>

# define INT_MAX 2147483647
# define FALSE 0
# define TRUE 1

// STATES
# define STATE_THINKING 2
# define STATE_EATING 3
# define STATE_SLEEPING 4
# define STATE_DEAD 5
# define STATE_FORK 6

typedef struct s_input
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_times_eat;
}						t_input;

typedef struct s_fork
{
	int	left;
	int	right;
}							t_fork;

typedef struct s_vars
{
	long long		init_time;
	int				philos_ate_count;
	int				game_over;
	t_input			inputs;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing_lock;
}							t_vars;

typedef struct s_philo
{
	t_fork				fork;
	long long			last_eat_time;	
	int					id;
	int					times_ate;
	int					state;
	t_vars				*vars;
	pthread_mutex_t		mutex;
	pthread_t			philo;
}							t_philo;

// utils.c
int				my_atoi(char *str);
void			printmessage(t_philo *philo, int state);
int				print_philo_state(t_philo *philo, int state);

// error_handling.c
int				my_errors(char *str);

// checking_args.c
int				check_args(t_input *inputs, char **av, int ac);

// create_philo.c
int				create_threads(t_vars *vars, int odd_even);

// main.c
long long		get_time_in_ms(void);
void			wait_ms(int ms);

// init.c
int				init_mutex(t_vars *vars);
int				init_philos(t_vars *vars);

// routines.c
int				philo_eating(t_philo *philo);
int				philo_sleeping(t_philo *philo);
int				philo_thinking(t_philo *philo);

// dead_check.c
void			dead_check(t_vars *vars);

// free.c
void			free_all(t_vars *vars);

#endif
