/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:46:53 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/09 15:52:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_corpse(void)
{
	int			corpse;

	pthread_mutex_lock(&dead_call()->killer);
	corpse = dead_call()->is_dead;
	usleep(100);
	pthread_mutex_unlock(&dead_call()->killer);
	if (corpse)
		return (0);
	return (1);
}

int	check_forks(t_philo *philos)
{
	philos->r_fork = (data_call()->philo_num - 1);
	philos->l_fork = data_call()->philo_num;
	pthread_mutex_lock(&forks_call()->forks);
	if (philos->r_fork)
	{
		print_message(philos, "is taking RIGHT fork");
		philos->r_fork = 1;
	}
	if (philos->l_fork == 0)
	{
		print_message(philos, "is taking LEFT fork");
		philos->l_fork = 1;
	}
	pthread_mutex_unlock(&forks_call()->forks);
	if (philos->l_fork && philos->r_fork)
		return (1);
	return (0);
}

int	philo_alive(t_philo *philos)
{
	long int	last;
	t_data		*data;

	if (!check_corpse())
		return (0);
	data = data_call();
	last = get_time() - philos->last_meal;
	if (last >= data->die_time)
	{
		pthread_mutex_lock(&dead_call()->killer);
		dead_call()->is_dead = 42;
		if (dead_call()->is_dead)
			print_message(philos, "died");
		pthread_mutex_unlock(&dead_call()->killer);
		return (0);
	}
	return (1);
}
