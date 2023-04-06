#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
	
long long int num;

long long	get_time_in_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	*routune(pthread_mutex_t *mutex)
{
	for (size_t i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(mutex);
		num++;
		printf("num: %lld\n", num);
		pthread_mutex_unlock(mutex);
	}
	return (NULL);
}

int	main()
{
	pthread_mutex_t	mutex;
	pthread_t	*th;
	int			i;
	
	num = 0;
	pthread_mutex_init(&mutex, NULL);
	th = (pthread_t *)malloc(sizeof(pthread_t) * 4);
	i = 0;
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, (void *)&routune, (void *) &mutex) != 0)
		{
			printf("an error has occurred!\n");
			return (-1);
		}
		printf("Thread %d has created!\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			printf("an error has occurred");
			return (-1);
		}
		printf("thread %d has finished\n", i);
		i++;
	}
	printf("Total: %lld", num);
	return 0;
}