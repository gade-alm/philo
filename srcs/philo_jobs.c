/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:45 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/06 12:55:19 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// void	philo_nap(t_philo *philos)
// {
// 	long int	nap_time;

// 	nap_time = get_time();
// 	if ()
// }

void	*philo_jobs(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	i = data_call()->philo_num;
	philos->last_meal = data_call()->start;
	while (philo_alive(philos))
	{
		// philo_nap(philos);
		usleep(150);
		if (philo_alive(philos))
			print_message(philos, "isn't working");
	}
	return (NULL);
}

