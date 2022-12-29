/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:45 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/29 19:22:19 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_jobs(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	i = -1;
	while (philo_alive(philos))
	{
		printf("%ld ms %i isn't working\n", get_time() - \
		philos->data->seconds, philos->id_num);
	}
	return (NULL);
}
