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

typedef struct s_fork
{
	int	left;
	int	right;
} 			t_fork;


typedef struct s_philo
{
	t_fork		fork;
	long long	last_eat_time;	
	int			id;
	int			times_ate;
	int			state;
	int			time_to_die;
	pthread_t	philo;
}						t_philo;


typedef struct s_input
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_eat;
}				t_input;

typedef struct s_vars
{
	int		game_over;
	t_input	inputs;
	t_philo	*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t	writing_lock;
}				t_vars;


// utils.c
int	my_atoi(char *str);

// error_handling.c
int	my_errors(char *str);

// checking_args.c
int	check_args(t_input *inputs, char **av, int ac);

// create_philo.c
int	create_philos(t_vars *vars, int odd_even);

// main.c
long long	get_time_in_ms(void);

// init_mutex.c
int	init_mutex(t_vars *vars);

#endif
