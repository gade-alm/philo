/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:45 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/11 18:57:24 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_nap(t_philo *philos)
{
	long int	nap_time;
	long int	napping;

	nap_time = get_time();
	napping = 0;
	print_message(philos, "is sleeping");
	usleep(200);
	while (napping <= data_call()->sleep_time && philo_alive(philos))
		napping = get_time() - nap_time;
	return ;
}

void	philo_eat(t_philo *philos)
{
	long int	eat_time;
	long int	eating;

	eat_time = get_time();
	eating = 0;
	usleep(200);
	if (check_forks(philos))
	{
		while (eating <= data_call()->eat_time && philo_alive(philos))
			eating = get_time() - eat_time;
		philos->last_meal = get_time();
		print_message(philos, "is eating");
	}	
	return ;
}

void	*philo_jobs(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	philos->last_meal = data_call()->start;
	while (philo_alive(philos))
	{
		philo_eat(philos);
		philo_nap(philos);
	}
	return (NULL);
}
