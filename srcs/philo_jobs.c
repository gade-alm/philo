/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:45 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/12 15:24:20 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_nap(t_philo *philos)
{
	long int	nap_time;
	long int	napping;

	nap_time = get_time();
	napping = 0;
	if (check_corpse())
		return (0);
	print_message(philos, "is sleeping");
	usleep(100);
	while (napping <= data_call()->sleep_time)
		napping = get_time() - nap_time;
	return (1);
}

int	philo_eat(t_philo *philos)
{
	long int	eat_time;
	long int	eating;

	eat_time = get_time();
	eating = 0;
	if (check_corpse())
		return (0);
	usleep(100);
	if (check_forks(philos))
	{
		print_message(philos, "is eating");
		while (eating <= data_call()->eat_time && philo_alive(philos))
			eating = get_time() - eat_time;
		usleep(100);
	}
	philos->last_meal = get_time();
	philos->times_eat++;
	return (1);
}

void	*philo_jobs(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	philos->last_meal = data_call()->start;
	while (philo_alive(philos))
	{
		philo_eat(philos);
		if (philos->times_eat == philos->data->must_eat_num)
			return (NULL);
		philo_nap(philos);
		print_message(philos, "is thinking");
	}
	return (NULL);
}
