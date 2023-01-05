/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:45 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/05 18:52:22 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_jobs(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	i = data_call()->philo_num;
	philos->last_meal = data_call()->start;
	while (philo_alive(philos))
	{
		print_message(philos, "isn't working");
	}
	return (NULL);
}
